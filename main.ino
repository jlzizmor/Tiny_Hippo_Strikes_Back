/* Jacob Zizmor
 * Group 1
 * Tiny Hippo
 *
 * RBE 2002
 * D02 '14
 *
 * The main function of our robot
*/

#include PID_v1
#include Servo.h
#include <start_button_ISR.ino>
#include <checkForce.ino>

// all Servo objects
Servo planetary;					// Servo which spins the planetary gears
Servo hook;							// Servo which moves the whinch hook forward and back
Servo eraser;						// Servo which moves the eraser into the robot and out
									// of the robot

// pins of each servo/motor
int planetary_pin = -1;				// pin of the planetary Servo
int hook_pin = -1;					// pin of the hook Servo
int eraser_pin = 1;					// pin of the eraser Servo

// pins
int legTL = -1;						// pin to the pot of the top left foot
int legTR = -1;						// pin to the pot of the top right foot
int legBL = -1;						// pin to the pot of the bottom left foot
int legBR = -1;						// pin to the pot of the bottom right foot

int eraser_pot = -1;				// pin to the pot of the eraser
int hook_pot = -1;					// pin to the pot of the hook
int buttonISR = -1;					// pin to the button which starts the ISR

// LEDs
int warningLED = -1;				// pin to the warning LED
int tlLED = -1;						// pin to light when the top left foot is making contact
int trLED = -1;						// pin to light when the top right foot is making contact
int blLED = -1;						// pin to light when the bottom left foot is making contact
int brLED = -1;						// pin to light when the bottom right foot is making contact

// PD
int eKp;							// the Kp value of the eraser
int eKd;							// the Kd value of the eraser

// Global variables
extern int to_do;					// the variable modified by the ISR
extern int run_main_function;		// the comparison to know when to start all actions
extern int tooMuch;					// comparison variable for too much force
extern int keepGoing;				// comparison variable to keep moving

void setup() {
	// attach all Servo objects
	planetary.attach(planetary_pin);							// attach the planetary motor
	hook.attach(hook_pin);										// attach the hook motor
	eraser.attach(eraser_pin);									// attach the eraser motor

	// pinMode
	pinMode(legTL, INPUT);										// set all of the pots to INPUT
	pinMode(legTR, INPUT);
	pinMode(legBL, INPUT);
	pinMode(legBR, INPUT);
	pinMode(eraser_pot, INPUT);

	pinMode(buttonISR, INPUT);									// set the button to INPUT

	pinMode(LED, OUTPUT);										// set the LED to OUTPUT

	// init ISR
	attachInterrupt(-1, start_button_ISR, RISING);				// initialize ISR
																// activates upon button press
																// while the ISR will run if the
																// button is pressed again, there
																// will be no lasting effect other
																// than a small time delay
																// **** -1 must be changed ****

	// adjust the hook till the robot is balanced
	hook_adjust(int legTL, int legTR, int legBL, int legBR);	// adjust the position of the hook
																// to balance the robot on the
																// current position of the board
																// NOTE: because the robot is not
																// moving around the board, there
																// is no need to check this position
																// at any other time. If the robot
																// were to move, this action should
																// be moved to loop() with PID
}

void loop() {
	if (to_do==run_main_function) {								// only begin motion when the ISR has
																// been activated, ie the button pressed
		while (contact(legTL, legTR, legBL, legBR)) {			// check the contact of all of the feet
			planetary.write(90);								// when the robot is off of the board, stop
																// the planetary gears from spinning
			eraser_in();										// bring the planetary system up into the
																// in order to be safe when placed back onto
																// the board, incase placed back on an angle
		}
		
		while (check_force_all(legTL, legTR, legBL, legBR)==tooMuch) {
			digitalWrite(warningLED, HIGH);						// light the LED symbolising too much force is
																// being applied
			planetary.write(90);								// stop the planetary gear from spinning
			eraser_in();										// bring in the planetary gear system as far as
																// possible
		}

		digitalWrite(warningLED, LOW);							// whether too much force was previously applied
																// or not, shut off the warning LED
		planetary.write(planetary_speed);						// spin the planetary gear

	// run PID of eraser
}