#include <PID_v1.h>
#include "encoder.h"
#include "motor.h"

#define pwm_pin 9
#define in1_pin 6
#define in2_pin 7
#define enc_pin 8

encoder enc;
motor mot;

bool init_flag = false;
volatile bool end_flag = false;


void endstopPressed(){  //ISR function
  end_flag = true;  
}

void setup() {
  Serial.begin(1000000);
  pinMode(3, INPUT);  // endstop
  attachInterrupt(1, endstopPressed, FALLING);
  enc.setPin(enc_pin);
  mot.setPins(pwm_pin, in1_pin, in2_pin);
  mot.setDir(0);
  enc.setDir(0);
}

void loop() {

  enc.measure();
  enc.printLaps(); 
  enc.printDir();
  
  if(!init_flag){
    if(end_flag){
      mot.stops();
      init_flag = true;
    }
  }
  else
    mot.setPwm(150);
  
  mot.move();

}
