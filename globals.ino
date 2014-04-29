/*
 * Group 1
 * Tiny Hippo
 * 
 * RBE 2002
 * D02 '14
 * 
 * This file contains all global variables used across functions
*/

// all global variables
int eraser_force = -1;		// the constant force required by the eraser system
							// -1 is the general use NULL value
							// everything will still compile, and when we calculate the correct value we can change the number
							
int to_do = 0;				// the general input variable
							// this variable will change based on the interrupt
							// input of the button(s) while equal to 0, nothing will run

int run_main_function = 1;	// the comparison to run the main function
							// compared with to_do

int eK = -1;				// spring constant of the spring used for the force sensor of the
							// eraser
int eIa = -1;				// analog read of pot used for the force sensor of the eraser at point
							// a, which is closer than point b
int eIb = -1;				// analog read of pot used for the force sensor of the eraser at point
							// b, which is farther that point a
int eXa = -1;				// distance assosiated with point a of pot used for the force sensor
							// of the eraser
int eXb = -1;				// distance assosiated with point b of pot used for the force sensor
							// of the eraser
int tooMuch = 1;			// comparison variable for too much force
int keep Going = 0;			// comparison variable to keep moving