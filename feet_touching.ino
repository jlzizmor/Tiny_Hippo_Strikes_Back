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

// check to see if the reading from the given foot is equal to or less than the minimum
// the minimum allows for the non-digital nature of the potentiometer
boolean foot_contact(int pin) {
	return analogRead(pin)<=min;	// return boolean result of this comparison
}