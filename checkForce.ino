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
 
//Move these to global section
 
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
