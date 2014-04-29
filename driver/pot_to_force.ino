/* Jacob Zizmor
 * Group 1
 * Tiny Hippo
 * 
 * RBE 2002
 * D02 '14
 *
 * Potentiometer Input to Force
*/
#include <pot_to_pos.ino>
extern int k;						// spring constant
extern int pot_zero;				// equilbrium position of the spring

// this function converts a potentiometer input to it's force value
// inputs:
	// k is the spring constant
	// ia is the analog input at position a
	// ib is the analog input at position b
	// xa is the position at a
	// xb is the position at b
	// val is the value to change to a force
// outputs: float value equal to the force
float pot_to_force(int k, int ia, int ib, int xa, int xb, int val) {
	float del_x = abs(pot_zero-pot_to_pos(ia, ib, xa, xb, val));  		// displacement
                                                                     	        // pot_zero is the equilibrium position
	return k*del_x;      // F=k*x
}

