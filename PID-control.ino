#include <PID_v1.h>
#include "encoder.h"
#include "motor.h"

#define pwm_pin 9
#define in1_pin 6
#define in2_pin 7
#define enc_pin 8

encoder enc;
motor mot;

int i = 50;
int j = 0;

void setup() {
  Serial.begin(1000000);
  enc.setPin(enc_pin);
  mot.setPins(pwm_pin, in1_pin, in2_pin);
  mot.setDir(1);
  enc.setDir(1);
}

void loop() {

  enc.measure();
  enc.printLaps(); 
  enc.printDir();
  
  if (i == 200){
  	i = 30;
    mot.toggleDir();
    enc.setDir(mot.getDir());
  }


  else{
  	if (j == 30){
  		mot.setPwm(i);
  		i++;
  		j = 0;
  	}
  	else
  		j++;
  }
  
  mot.move();

}
