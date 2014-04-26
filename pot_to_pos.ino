/* Jacob Zizmor
 * Group 1
 * Tiny Hippo
 * 
 * RBE 2002
 * D02 '14
 *
 * Potentiometer Input to Position
*/

// This function converts a pot input to its position
// inputs:
//	ia = the analog reading at point a
//	ib = the analog reading at point b
//	xa = the position at point a
//	xb = the position at point b
//	pin = the pin of the pot
// output: the position at the current state
int pot_to_pos(int ia, int ib, int xa, int xb, int pin) {
	int del_i = abs(ib-ia);	// the change in input readings
	int del_x = abs(xb-xa);
}