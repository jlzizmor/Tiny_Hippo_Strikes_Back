/* Jacob Zizmor
 * Group 1
 * Tiny Hippo
 *
 * RBE 2002
 * D02 '14
 *
 * This function will check to see if the robot's foot is touching the board.
 * Contact of a foot is checked for an individual foot.
*/

int min_read = -1;						// the minimum analog read value which represents no
										// contact between a foot and the board

// check to see if the reading from the given foot is equal to or less than the minimum
// the minimum allows for the non-digital nature of the potentiometer
// input:
//	pin: the pin of the foot to check
// output:
//	boolean value, true is in contact
boolean foot_contact(int pin) {
	return analogRead(pin)<=min_read;	// return boolean result of this comparison
}

// check if any of the feet are in contact as well as turning on the proper
// LEDs
// first checks which feet are in contact
// then turns on the LEDs for those feet which are in contact
//	contact uses the definition provided in foot_contact()
// inputs:
//	oneF = pin of foot 1
//	twoF = pin of foot 2
//	threeF = pin of foot 3
//	fourF = pin of foot 4
//	oneL = LED corresponding to foot 1
//	twoL = LED corresponding to foot 2
//	threeL = LED corresponding to foot 3
//	fourL = LED corresponding to foot 4
// output:
//	a boolean value if all four feet are in contact
//	true for all in contact
boolean contact(int oneF, int twoF, int threeF, int fourF, int oneL, int twoL, int threeL, int fourL) {
	boolean feet[4];			// results for each check on contact for feet 1-4
	int leds[4] = {oneL, twoL, threeL, fourL};	// pins of each led

	// preform all checks
	feet[0] = foot_contact(oneF);
	feet[1] = foot_contact(twoF);
	feet[2] = foot_contact(threeF);
	feet[3] = foot_contact(fourF);

	for (int i = 0; i < 4; i++) {
		if (feet[i]) {						// if the foot is in contact
			digitalWrite(leds[i], HIGH);	// turn on its LED
		}
		else {
			digitalWrite(leds[i], LOW);		// otherwise, turn its LED off
		}
	}

	return feet[0] && feet[1] && feet[2] && feet[3];	// if none of the
														// feet are in
														// contact,
														// return false
														// otherwise,
														// return true
}
