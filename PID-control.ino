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
  mot.set_pins(pwm_pin, in1_pin, in2_pin);
  mot.set_dir(1);
}

void loop() {

  enc.measure();
  enc.printLaps(); 

  if (i == 250)
  	i = 50;

  else{
  	if (j == 10){
  		mot.set_pwm(i);
  		i++;
  		j = 0;
  	}
  	else
  		j++;
  }


  mot.move();

}
