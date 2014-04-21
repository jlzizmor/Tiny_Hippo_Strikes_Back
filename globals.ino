/*
 * Group 1
 * Tiny Hippo
 * 
 * RBE 2002
 * D02 '14
 * 
 * This file contains all global variables used across functions
*/

// all Servo objects
Servo planetary;
Servo hook;
Servo eraser;

// pins of each servo/motor, to be attached later
int hook_pin = -1;
int planetary_pin = -1;
int eraser_pin = 1;

// all other variables
int eraser_force = -1;		// the constant force required by the eraser system
							// -1 is the general use NULL value

							// everything will still compile, and when we calculate the correct value we can change the number
int to_do = 0;				// the general input variable
							// this variable will change based on the interrupt input of the button(s)
							// while equal to 0, nothing will run

int run_main_function = 1;	// the comparison to run the main function
							// compared with to_do

float acc_err_feet = -1.0;	// the accepted error for the verticle comparison of the top feet and bottom feet
							// based on the hook movement design, v1
