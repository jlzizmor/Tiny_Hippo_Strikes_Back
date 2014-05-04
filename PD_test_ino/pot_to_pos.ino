/* Jacob Zizmor
 * Group 1
 * Tiny Hippo
 * 
 * RBE 2002
 * D02 '14
 *
 * Potentiometer Input to Position
 */
float ans;

// This function converts a pot input to its position
// inputs:
//	ia = the analog reading at point a
//	ib = the analog reading at point b
//	xa = the position at point a
//	xb = the position at point b
//	val = the value of to change to position
// output: the position at the current state
float pot_to_pos(int ia, int ib, int xa, int xb, int val) {
  int del_i = abs(ib-ia);	// the change in input readings
  int del_x = abs(xb-xa);	// the change in position

  float slope = ((float)del_x)/((float)del_i);	// the slope of the line
  // in the form mx+b
  // using known values of the pot can be used
  // to make a formula relating an input
  // to the position
  // because there is no software offset,
  // b == 0
  return slope*val;
}

