/*
 * Group 1
 * Tiny Hippo
 * 
 * RBE 2002
 * D02 '14
 * 
 * This file contains all global variables used across functions
*/

int eraser_force = -1;		// the constant force required by the eraser system
							// -1 is the general use NULL value
							// everything will still compile, and when we calculate the correct value we can change the number
int to_do = 0;				// the general input variable
							// this variable will change based on the interrupt input of the button(s)
							// while equal to 0, nothing will run
int run_main_function = 1;	// the comparison to run the main function
							// compared with to_do