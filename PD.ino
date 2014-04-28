/* Jacob Zizmor
 * Group 1
 * Tiny Hippo
 *
 * RBE 2002
 * D02 '14
 * 
 * This set of functions runs PD control.
 *
 * The functions for PD control are coded for controlling our eraser specifically
 * because the robot will not be moving. If there were other parts moving, the code would
 * have to be adjusted.
*/

int current = 0;						// the current read in of the sensor
int last = 0;							// the last sensor value read

int PD(int pin, int kp, int kd) {
	last = current;						// set the previously read sample to the last variable
	current = analogRead(pin);			// read in the new sample

	return calculatePD(kp, kd);				// return the result of the PD calculation
}

int calculatePD(int kp, int kd) {
	int error = calcE();				// calculate the error
	float result = P(error, kp);		// result is equal to the sum of the P calculation and the D calculation
	result = result + D(error, kd);		// displayed in 2 parts
	return (int)result;					// return the integer value of the result, such that the Arduino can process it
}

float P(e, kp) {
	return (float)kp*e;
}

float D(e, kp) {
	return 
}