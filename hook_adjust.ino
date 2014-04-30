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
int hookspeed = -1;
int front_rail_switch = -1;
int back_rail_switch = -1;


//this function calls the checkFeetPosition () to see if the robot is topheavy, bottomheavy, or balanced
//It then drives the motor to adjust the hook until the robot is balanced or when
//either limit switch is pressed, in which case the motor is stopped.

void hook_adjust(int pin1, int pin2, int pin3, int pin4){
	int check_balance = checkFeetPosition(pin1,pin2,pin3,pin4);
	int frontswitch = analogRead(front_rail_switch);
	int backswitch = analogRead(back_rail_switch);
	int not_pressed = 0

	while ((check_balance != balance) && (frontswitch == not_pressed) && (backswitch == not_pressed) ) //when the robot is not balanced and both limit switches are not pressed, do the following:
	{ 
	
	if (checkFeetPosition(pin1, pin2, pin3, pin4) == topHeavy){ 
		hook_pin.write(hookspeed); //shift the hook forward if topheavy
	}
	else if(checkFeetPosition(pin1, pin2, pin3, pin4) == bottomHeavy){
		hook_pin.write(hookspeed-180); //shift the hook backwards if bottomheavy
	}
	else hook_pin.write(90); //stops the motor //otherwise stop the motor
	check_balance = checkFeetPosition(pin1,pin2,pin3,pin4); //resets the blance check to it's proper value
	}

	hookpin.write(90); //stops the motor in case it is still running
}
