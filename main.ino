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

// all Servo objects
Servo planetary;			// Servo which spins the planetary gears
Servo hook;					// Servo which moves the whinch hook forward and back
Servo eraser;				// Servo which moves the eraser into the robot and out of the robot

// pins of each servo/motor
int planetary_pin = -1;		// pin of the planetary Servo
int hook_pin = -1;			// pin of the hook Servo
int eraser_pin = 1;			// pin of the eraser Servo

// variables
int eKp;		// the Kp value of the eraser
int eKd;		// the Kd value of the eraser
int eKi;		// the Ki value of the eraser

// pins
int legTL = -1;		// pin to the pot of the top left foot
int legTR = -1;	// pin to the pot of the top right foot
int legBL = -1;	// pin to the pot of the bottom left foot
int legBR = -1;	// pin to the pot of the bottom right foot

void setup() {
	// attach all Servo objects
	planetary.attach(planetary_pin);						// attach the planetary motor
	hook.attach(hook_pin);									// attach the hook motor
	eraser.attach(eraser_pin);								// attach the eraser motor

	// pinMode
	// init PID
	hook_adjust(int legTL, int legTR, int legBL, int legBR); // adjust the position of the hook
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
	// inside while loop until ISR
	// check force for too much force
		// light LED in while loop

	// run PID of eraser
}