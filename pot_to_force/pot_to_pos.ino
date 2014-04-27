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

/*
void setup() {
  Serial.begin(115200);
  ans = 0;
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.println(pot_to_pos(0,895,0,1,A0));		// 0 and 895 are the pot limits, not for the force sensor
  												// 0 and 1 are for reference
  delay(100);
}
*/

// This function converts a pot input to its position
// inputs:
//	ia = the analog reading at point a
//	ib = the analog reading at point b
//	xa = the position at point a
//	xb = the position at point b
//	pin = the pin of the pot
// output: the position at the current state
float pot_to_pos(int ia, int ib, int xa, int xb, int pin) {
	int del_i = abs(ib-ia);	// the change in input readings
	int del_x = abs(xb-xa);	// the change in position

	float slope = ((float)del_x)/((float)del_i);	// the slope of the line
													// in the form mx+b
													// using known values of the pot can be used
														// to make a formula relating an input
														// to the position
													// because there is no software offset,
														// b == 0
	return slope*analogRead(pin);
}
