/* Jacob Zizmor
 * Group 1
 * Tiny Hippo
 *
 * RBE 2002
 * D02 '14
 *
 * The main function of our robot
*/

#include "Servo.h"
#include <start_button_ISR.ino>
#include <checkForce.ino>
#include <PD.ino>
#include <checkFeetPosition.ino>
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
int eKp = -1;						// the Kp value of the eraser
int eKd = -1;						// the Kd value of the eraser
int magnitude = 90;					// the magnitude to drive the motor
int read = 0;						// the read of the motor in order to logic the direction
int a1 = -1;						// logic pin 1 of H bridge
int a2 = -1;						// logic pin 2 of H bridge

// motor speeds
int planetary_speed = -1;			// the speed at which the planetary motor spins

// Global variables
extern int eraser_force;			// the force to be applied by the eraser
extern int to_do;					// the variable modified by the ISR
extern int run_main_function;		// the comparison to know when to start all actions
extern int tooMuch;					// comparison variable for too much force
extern int keepGoing;				// comparison variable to keep moving
extern int k;						// spring k value
									// all the springs used have the same k value
extern int eIa;						// analog reading from the eraser pot at position a
extern int eIb;						// analog reading from the eraser pot at position b
extern int eXa;						// distance of eraser pot at position a
extern int eXb;						// distance of eraser pot at position b
extern int ibTL;					// analog read of the top left foot at the extent, point b
extern int ibTR;					// analog read of the top right foot at the extent, point b
extern int ibBL;					// analog read of the bottom left foot at the extent, point b
extern int ibBR;					// analog read of the bottom right foot at the extent, point b

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

	pinMode(warningLED, OUTPUT);								// set the LEDs to OUTPUT
	pinMode(tlLED, OUTPUT);
	pinMode(trLED, OUTPUT);
	pinMode(blLED, OUTPUT);
	pinMode(brLED, OUTPUT);

	// init ISR
	attachInterrupt(-1, start_button_ISR, RISING);				// initialize ISR
																// activates upon button press
																// while the ISR will run if the
																// button is pressed again, there
																// will be no lasting effect other
																// than a small time delay
																// **** -1 must be changed ****

	// adjust the hook till the robot is balanced
	hook_adjust(legTL, legTR, legBL, legBR);	// adjust the position of the hook
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
	if (to_do==run_main_function) {															// only begin motion when the ISR has
																							// been activated, ie the button pressed
		while (contact(legTL, legTR, legBL, legBR, tlLED, trLED, blLED, brLED)) {			// check the contact of all of the feet
			planetary.write(90);															// when the robot is off of the board, stop
																							// the planetary gears from spinning
			eraser_in();																	// bring the planetary system up into the
																							// in order to be safe when placed back onto
																							// the board, incase placed back on an angle
		}
		
		while (check_force_all(legTL, legTR, legBL, legBR, ibTL, ibTR, ibBL, ibBR)==tooMuch) {
			digitalWrite(warningLED, HIGH);													// light the LED symbolising too much force is
																							// being applied
			planetary.write(90);															// stop the planetary gear from spinning
			eraser_in();																	// bring in the planetary gear system as far as
																							// possible
		}

		digitalWrite(warningLED, LOW);														// whether too much force was previously applied
																							// or not, shut off the warning LED
		planetary.write(planetary_speed);													// spin the planetary gear

		// run PD for eraser
		magnitude = PD(eraser_pot, eKp, eKd);												// use PD to get the magnitude to drive the motor
		read = analogRead(eraser_pot);														// record the position of the pot
		if (pot_to_force(k, eIa, eIb, eXa, eXb, analogRead(eraser_pot)) > eraser_force) {	// set direction to spin the motor
			logic_in();
		}
		else {
			logic_out();
		}
		eraser.write(magnitude);
	}
}

void logic_in() {
	digitalWrite(a1, HIGH);
	digitalWrite(a2, LOW);
}

void logic_out() {
	digitalWrite(a1, LOW);
	digitalWrite(a2, HIGH);
}

void hook_adjust(int a, int b, int c, int d) {}	// not the actual function, a placeholder so it will compile

void eraser_in() {}	// not actual function, placeholder so it will compile
