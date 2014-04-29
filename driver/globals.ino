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
int eXa = 0;				// distance assosiated with point a of pot used for the force sensor
							// of the eraser, in inches
int eXb = 1;				// distance assosiated with point b of pot used for the force sensor
							// of the eraser, in inches
int ibTL = -1;				// analog read of the top left foot at the extent, point b
int ibTR = -1;				// analog read of the top right foot at the extent, point b
int ibBL = -1;				// analog read of the bottom left foot at the extent, point b
int ibBR = -1;				// analog read of the bottom right foot at the extent, point b

int tooMuch = 1;			// comparison variable for too much force
int keepGoing = 0;			// comparison variable to keep moving

int k = -1;					// the k value of the springs used
							// all the springs used have the same k value
int pot_zero = -1;				// equilbrium position of the spring
