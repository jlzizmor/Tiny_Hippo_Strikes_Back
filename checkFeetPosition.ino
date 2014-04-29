/*Arthur Fulgoni
 *RBE 2002
 *D02 '14
 *Group 1
 *Tiny Hippo
 *
 *This function compares the position of the top feet and the
 *position of the bottom feet
 *
 */

//Move these to globals
int balance = 0;             //When robot is in balanced position
int topHeavy = 1;            //When the top of the robot is leaning into the board 
int bottomHeavy = -1;        //When the bottom of the robot is leaning into the board

//All Vcc legs are the same
//This function reads in values from pins connected to pots
//the value is the pot value at a given position
//it then takes the values of the top feet and averages them
//then takes the values of the bottom feet and averages them
//Compares the values of the top feet and the bottom feet
//returns a value based on the comparison
int checkFeetPosition(int pin1, int pin2, int pin3, int pin4){
  // instanciate variables
  int topValue1, topValue2, bottomValue1, bottomValue2, topAvg, bottomAvg;
  
  // initializes to the value of the potentiometer
  topValue1 = analogRead(pin1);
  topValue2 = analogRead(pin2);
  bottomValue1 = analogRead(pin3);
  bottomValue2 = analogRead(pin4);
  
  // calculate the average of the top and bottom feet
  topAvg = (topValue1 + topValue2)/2;
  bottomAvg = (bottomValue1 + bottomValue2)/2;
  
  // compare the values of the top and bottom feet
  if (topAvg > bottomAvg){
    return topHeavy;        //the top of the robot is leaning into the board
  }
  
  else if(topAvg < bottomAvg){
    return bottomHeavy;     //the bottom of the robot is leaning into the board
  }
  
  else{
    return balance;         //the position of the robot is balanced on the board
  }
}


