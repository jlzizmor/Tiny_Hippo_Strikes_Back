/* Jacob Zizmor
 * Group 1
 * Tiny Hippo
 *
 * RBE 2002
 * D02 '14
 *
 * This file contains the two ISR functions.
 * One which acts upon the start button
 * The other which is used by TimerOne
*/

#include <globals.ino>

extern int to_do;
extern int run_main_function;
extern int time;

// This function sets the to_do variable to symbolize starting
// Inputs: none
// Outputs: none
void start_button_ISR() {
	to_do = run_main_function;
}

// This function increments time on the command of TimerOne
void timer() {
	time++;
}
