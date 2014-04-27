/* Jacob Zizmor
 * Group 1
 * Tiny Hippo
 * 
 * RBE 2002
 * D02 '14
 *
 * Potentiometer Input to Force
*/

int k = 2;

void setup() {
	Serial.begin(115200);
}

void loop() {
	Serial.println(pot_to_force(k, 0, 895, 0, 1, A0));
	delay(100);
}

// this function converts a potentiometer input to it's force value
// inputs:
	// k is the spring constant
	// ia is the analog input at position a
	// ib is the analog input at position b
	// xa is the position at a
	// xb is the position at b
	// pin is the pin of the pot being referenced
// outputs: float value equal to the force
float pot_to_force(int k, int ia, int ib, int xa, int xb, int pin) {
	float del_x = abs(pot_zero-pot_to_pos(ia, ib, xa, xb, pin));
	return k*del_x;
}

