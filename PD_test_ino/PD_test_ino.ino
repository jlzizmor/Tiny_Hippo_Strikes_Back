#include "Servo.h"
#include <pot_to_force.ino>
#include <pot_to_pos.ino>

int eraser_pot = A8;
int eKp = 125;
int eKd = 1000;
int magnitude = 0;
int k = 200;
int eIa = 0;
int eIb = 994;
int eXa = 0;
int eXb = 1;
Servo eraser;
Servo planet;
int eraser_force = 1;
int limf = 31;
int limb = 37;


void setup() {
  eraser.attach(9,1000,2000);
  planet.attach(11,1000,2000);
}

void loop() {
  planet.write(130);
  if ((digitalRead(limf) == 0) || (digitalRead(limb) == 0)) {
    eraser.write(90);
  }
  else {
    int cur = (int)pot_to_force(k, eIa, eIb, eXa, eXb, analogRead(eraser_pot));
    int err = eraser_force-cur;
    int mag = eKp*err;

    if (cur < eraser_force) {
      mag = 180-mag;
    }
    eraser.write(mag);
  }
}

