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
Servo planetary;			// Servo which spins the planetary gears
Servo hook;					// Servo which moves the whinch hook forward and back
Servo eraser;				// Servo which moves the eraser into the robot and out of the robot

// pins of each servo/motor, to be attached later
int hook_pin = -1;			// pin of the hook Servo
int planetary_pin = -1;		// pin of the planetary Servo
int eraser_pin = 1;			// pin of the eraser Servo

// pins
int top_left_foot = -1;		// pin to the pot of the top left foot
int top_right_foot = -1;	// pin to the pot of the top right foot
int bottom_left_foot = -1;	// pin to the pot of the bottom left foot
int bottom_right_foot = -1;	// pin to the pot of the bottom right foot

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

const int CQ_SIZE = 10;		// the size of the circular queue used for sampling the eraser pot readings
float pot_read_CQ[CQ_SIZE];	// the circular queue used for sampling the eraser pot readings
							// the data type is an array of floats, although it will be used as a circular queue, inspired by homework 4 question 2