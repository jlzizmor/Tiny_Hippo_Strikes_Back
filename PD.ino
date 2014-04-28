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

int current_e = 0;						// the current read in of the sensor
static int last_e = 0;					// the last error calculated
int current_time = 0;					// the current time at which the sample is taken
static int last_time = 0;				// the time at which the last sample was taken

// controls all PD actions
// also gathers all necesary information, makes not calculations
// inputs:
//	pin = pin to poll to get sample
//	kp = proportional constant
//	kd = derivative constant
// output:
//	the magnetude of which to drive the motor
int PD(int pin, int kp, int kd) {
	current_e = analogRead(pin);		// read in the new sample
	current_time = millis();			// record the time at which the sample is taken
										// although recording the time is not taken simultaniously to recording the sample
										// because the time will be taken at the same point each time the method is run,
										// with the same processes run before it, the time difference will still be the same.
	return calculatePD(kp, kd);			// return the result of the PD calculation
}

// organizes all calculations for PD
int calculatePD(int kp, int kd) {
	int error = calcE();				// calculate the error
	int result = P(error, kp);			// result is equal to the sum of the P calculation and the D calculation
	result = result + D(error, kd);		// displayed in 2 parts
	last_e = error;						// record the last error calculated
	last_time = current_time;			// recotd the last time taken
	return result;						// return the integer value of the result, such that the Arduino can process it
}

int P(e, kp) {
	return (float)kp*e;
}

int D(e, kp) {
	int del_e = e-last_e;				// delta e, change in error values
	int del_t = current_time-last_time;	// delta t, change in time since last sample taken
}