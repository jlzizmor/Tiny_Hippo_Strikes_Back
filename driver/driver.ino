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
#include "TimerOne.h"
#include <ISRs.ino>
#include <checkForce.ino>
#include <PD.ino>
#include <checkFeetPosition.ino>
#include <checkForce.ino>
#include <hook_adjust.ino>

// all Servo objects
Servo planetary;					// Servo which spins the planetary gears
Servo hook;							// Servo which moves the whinch hook forward and back
Servo eraser;						// Servo which moves the eraser into the robot and out
									// of the robot

// pins of each servo/motor
int planetary_pin = 11;				// pin of the planetary Servo
int hook_pin = 10;					// pin of the hook Servo
int eraser_pin = 9;					// pin of the eraser Servo

// pins
int legTL = A0;						// pin to the pot of the top left foot
int legTR = A1;						// pin to the pot of the top right foot
int legBL = A2;						// pin to the pot of the bottom left foot
int legBR = A3;						// pin to the pot of the bottom right foot

int eraser_pot = A8;				// pin to the pot of the eraser
int buttonISR = 2;					// pin to the button which starts the ISR

int eLimO = 31;						// pin of the outter limit switch for the eraser
int eLimI = 37;						// pin of the inner limit switch for the eraser

// LEDs
int warningLED = 22;				// pin to the warning LED
int fLED = 23;						// pin to light when the feet are making contact

// PD
int eKp = 125;						// the Kp value of the eraser
int eKd = 1000;						// the Kd value of the eraser
int magnitude = 90;					// the magnitude to drive the motor
int read = 0;						// the read of the motor in order to logic the direction
int a1 = 34;						// logic pin 1 of H bridge
int a2 = 35;						// logic pin 2 of H bridge

// motor speeds
int planetary_speed = 130;			// the speed at which the planetary motor spins

// Frequency Example
int freq_ex = 29;					// the pin to show the sampling frequency

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
extern int t1;						// period of frequency 1(100 Hz) [ms]
extern int t2;						// period of frequency 2(500 Hz) [ms]
extern int time;					// counter for TimerOne ISR

void setup() {
	// attach all Servo objects
	planetary.attach(planetary_pin,1000,2000);					// attach the planetary motor
	hook.attach(hook_pin,1000,2000);							// attach the hook motor
	eraser.attach(eraser_pin,1000,2000);						// attach the eraser motor

	// pinMode
	pinMode(legTL, INPUT);										// set all of the pots to INPUT
	pinMode(legTR, INPUT);
	pinMode(legBL, INPUT);
	pinMode(legBR, INPUT);
	pinMode(eraser_pot, INPUT);

	pinMode(buttonISR, INPUT);									// set the button to INPUT

	pinMode(warningLED, OUTPUT);								// set the LEDs to OUTPUT
	pinMode(fLED, OUTPUT);

	pinMode(eLimI, INPUT);										// set the limit switches to INPUT
	pinMode(eLimO, INPUT);

	// init ISR
	attachInterrupt(0, start_button_ISR, RISING);				// initialize ISR
																// activates upon button press
																// while the ISR will run if the
																// button is pressed again, there
																// will be no lasting effect other
																// than a small time delay

	// TimerOne ISR
	Timer1.initialize(t1);										// initialize the timer to the
																// desired sampling period
	Timer1.attachInterrupt(timer);								// attach the timer ISR 

	hook_adjust(legTL, legTR, legBL, legBR);					// adjust the position of the hook
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
	time = 0;																				// reset the value of time from the last loop
																							// this is outside of the if statement so that
																							// incase there is a long delay between starting
																							// the Arduino and beginning the ISR, the value of

	if (to_do==run_main_function) {															// only begin motion when the ISR has
		digitalWrite(freq_ex, HIGH);															// turn on the freq_ex to show the sampling is running
																							// been activated, ie the button pressed
		while (contact(legTL, legTR, legBL, legBR, fLED)) {								// check the contact of all of the feet
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
		if ((digitalRead(eLimI)==1) || (digitalRead(eLimO)==1)) {							// if the eraser is at either extreme of its movement
			eraser.write(90);																// turn off the motor
		}
		magnitude = PD(eraser_pot, eKp, eKd);												// use PD to get the magnitude to drive the motor
		if (magnitude < 0) {
			magnitude = 0;
		}
		else if (magnitude > 90) {
			magnitude = 90;
		}
		read = analogRead(eraser_pot);														// record the position of the pot
		if (pot_to_force(k, eIa, eIb, eXa, eXb, analogRead(eraser_pot)) > eraser_force) {	// set direction to spin the motor
			logic_in(magnitude);
		}
		else {
			logic_out(magnitude);
		}
		eraser.write(magnitude);
		digitalWrite(freq_ex, LOW);														// turn off the freq_ex pin
		while (time < 1) {
			
		}																// while the full period has not elapsed yet, wait
	}
}

int logic_in(int mag) {
	return 180-mag;
}

int logic_out(int mag) {
	return mag;
}

void eraser_in() {
	while (eLimI != 0) {		// while the eraser has not moved in
		eraser.write(40);		// turn the motor to turn in
	}
}
