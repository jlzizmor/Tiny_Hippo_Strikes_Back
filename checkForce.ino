/*Arthur Fulgoni
 *RBE 2002
 *Group 1 
 *D02 '14
 *Tiny Hippo
 *
 *This function takes a value from a pin and checks to see if it is
 *at the limit
 *to be used for pots
*/
 
#include <globals.ino>

extern int tooMuch;		// result if too much force is being applied to a pin
extern int keepGoing;	// result if less than the maximum force is applied
						// to a pin
 
//This function reads in a value from a pin
//the value is the potentiometer value at a given position
//it determines whether the position is at is limit or not
//returns a value depending on the outcome 
int checkForce(int pin){
  
  int value;                  //intializes value
  value = analogRead(pin);    //assigns value to the potentiometer reading at a given pin value
  if (value == ia){           //if the value of the pot is equal to the value of the pot when
  							  //its at its limit of in towards the robot 
    return tooMuch;           //return there is too much force applied
  }
  else{                       //if the value of the pot is not at the limit
    return keepGoing;         //return the force applied is ok
  }
}

// this function uses the above funtion to check all 4 feet
// inputs:
//	one: pin of foot 1
//	two: pin of foot 2
//	three: pin of foot 3
//	four: pin of foot 4
// output:
//	tooMuch if any of the feet result in too much force
//	keepGoing otherwise
// modified by Jacob Zizmor
int check_force_all(int one, int two, int three, int four) {
	int pt1 = checkForce(one);			// result of check on foot 1
	int pt2 = checkForce(two);			// result of check on foot 2
	int pt3 = checkForce(three);		// result of check on foot 3
	int pt4 = checkForce(four);			// result of check on foot 4

	// if too much force is being applied to at least one of the feet
	// return tooMuch
	if ((pt1 == tooMuch) || (pt2 == tooMuch) || (pt3 == tooMuch) || (pt4 == tooMuch)) {
		return tooMuch;
	}

	else {
		return keepGoing;
	}
}