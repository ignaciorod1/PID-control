#include <PID_v1.h>
#include "encoder.h"
#include "motor.h"

#define pwm_pin 9
#define in1_pin 6
#define in2_pin 7
#define enc_pin 8
#define endstop_pin 12

encoder enc;
motor mot;

bool init_flag = false;
volatile bool end_flag = false;

void endstopPressed(){  //ISR function
  end_flag = true;  
}

void setup() {
  Serial.begin(1000000);

  pinMode(12, INPUT);  // endstop
  attachInterrupt(0, endstopPressed, FALLING);

  enc.setPin(enc_pin);
  enc.setDir(1);

  mot.setDir(1);
  mot.setPins(pwm_pin, in1_pin, in2_pin);
}

void loop() {

  enc.measure();
  enc.printLaps(); 
  enc.printDir();
/*
  if(!init_flag){
    if(end_flag){
      mot.stops();
      init_flag = true;
    }
  }
  else*/
      mot.setPwm(100);


  Serial.println(init_flag);

  mot.move();
}
