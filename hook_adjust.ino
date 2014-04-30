/*Joshua Friscia
 *RBE 2002
 *D02 '14
 *Group 1
 *Tiny Hippo
 *
 *This function checks if the robot is balanced 
 *and then runs the motor accordingly if the robot is too topheavy or bottomheavy
 *
 */
#include Servo.h
#include checkFeetPosition.ino
extern hook_pin;
extern balance;
extern topHeavy;
extern bottomHeavy;

//make these gloabl variables
int hookspeed = -1;		//speed the hook's motor turns
int front_rail_switch = -1;	//pin number of the front rail limit switch
int back_rail_switch = -1;	//pin number of the back rail limit switch


//This function takes in the four pins that coorespond to the four linear potentiometers on the feet and plugs them into the
//the checkFeetPosition () function to see if the robot is topheavy, bottomheavy, or balanced.
//It then drives the motor to adjust the hook until the robot is balanced or when
//either limit switch is pressed, in which case the motor is stopped.

void hook_adjust(int pin1, int pin2, int pin3, int pin4){
	
	//create variables
	int check_balance = checkFeetPosition(pin1,pin2,pin3,pin4);	//sets variable equal to result of checkFeetPosition() function
	int frontswitch = analogRead(front_rail_switch);	//front limit switch value
	int backswitch = analogRead(back_rail_switch);		//back limit switch value
	int not_pressed = 0;

	//when the robot is not balanced and both limit switches are not pressed
	while ((check_balance != balance) && (frontswitch == not_pressed) && (backswitch == not_pressed) ){ 

		//if the robot is top  heavy 
		if (checkFeetPosition(pin1, pin2, pin3, pin4) == topHeavy){ 
			hook_pin.write(hookspeed); //shift the hook forward
		}

		//if the robot is bottomheavy
		else if(checkFeetPosition(pin1, pin2, pin3, pin4) == bottomHeavy){
			hook_pin.write(hookspeed-180); //shift the hook backwards
		}

		//otherwise the robot should be balanced
		else {
			hook_pin.write(90); //stops the motor //otherwise stop the motor
				check_balance = checkFeetPosition(pin1,pin2,pin3,pin4); //resets the balance check to it's proper value
		}		
	}

	hook_pin.write(90); //stops the motor in case it is still running
}
