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
int eraser_force = 1;		// the constant force required by the eraser system [N]
							
int to_do = 0;				// the general input variable
							// this variable will change based on the interrupt
							// input of the button(s) while equal to 0, nothing will run

int run_main_function = 1;	// the comparison to run the main function
							// compared with to_do
							
int k = -1;					// spring constant of the spring used for the force sensor
int eIa = 0;				// analog read of pot used for the force sensor of the eraser at point
							// a, which is closer than point b
int eIb = 994;				// analog read of pot used for the force sensor of the eraser at point
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

int pot_zero = -1;			// equilbrium position of the spring

int hookspeed = -1;			//speed the hook's motor turns
int front_rail_switch = -1;	//pin number of the front rail limit switch
int back_rail_switch = -1;	//pin number of the back rail limit switch

int freq1 = 100;			// sampling frequency 1 [Hz]
int t1 = 10000;				// period of frequency 1 [us]
int freq2 = 500;			// sampling frequency 2 [Hz]
int t2 = 2000;					// period of frequency 2 [us]
int time = 0;				// the time counter, to be modified by TimerOne
