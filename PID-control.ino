#include <PID_v1.h>
#include "encoder.h"
#include "motor.h"

#define pwm_pin 9
#define in1_pin 6
#define in2_pin 7
#define enc_pin 8

encoder enc;
motor mot;

volatile bool end_flag = false;


void endstopPressed(){  //ISR function
  end_flag = true;  
}

void homing(){
  if(end_flag)
      mot.stops();
  else
    mot.setPwm(75);
}

void setup() {
  Serial.begin(1000000);

  pinMode(3, INPUT);  // endstop
  attachInterrupt(1, endstopPressed, FALLING);

  enc.setPin(enc_pin);
  mot.setPins(pwm_pin, in1_pin, in2_pin);
  mot.setDir(1);
  enc.setDir(1);
}

void loop() {

  enc.measure();
  enc.printLaps(); 
  enc.printDir();
  
  homing();

  mot.move();

}
