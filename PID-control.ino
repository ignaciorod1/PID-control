#include <Time.h>
#include <TimeLib.h>

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
bool r_flag = false;
bool init_flag = false;
int i = 0;
int readVal = 0;

double setPoint = 0;
double pid_input = 0;
double pid_output = 0;  //pwm output
double Kp = 0.06;
double Ki = 0.07;
double Kd = 0;

PID myPID (&pid_input, &pid_output, &setPoint, Kp, Ki, Kd, DIRECT);

void endstopPressed(){  //ISR function
  end_flag = true;  
}

void homing(){  // goes to 0 until it hits the endstop
  if(end_flag){
      if(r_flag){
        mot.stops();
        init_flag = true;
      }
      else{      // frees the endstop switch so its not fully pressed counting 10000 cycles (a bit lazy, I know)
        if(i == 1000)  r_flag = true;
        else{
          mot.setDir(1);
          enc.setDir(1);
          i++;
        }
      }     
  }
  else{;}
    
}

void setup() {
  Serial.begin(1000000);

  pinMode(3, INPUT);  // endstop
  attachInterrupt(1, endstopPressed, FALLING);

  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(Kp, Ki, Kd);

  enc.setPin(enc_pin);
  mot.setPins(pwm_pin, in1_pin, in2_pin);
  mot.setDir(0);
  enc.setDir(0);
  mot.setPwm(75);

  setPoint = 1000;
}

void loop() {

  enc.measure();
  //enc.printLaps(); 
  //enc.printDir();
  //enc.printRPM();
  
  Serial.print("RPM: ");
  Serial.print(enc.getRPM());
  Serial.print("  PID output: ");
  Serial.println(pid_output);
  
  if(!init_flag)
    homing();


  else if(init_flag){

    mot.setDir(1);
    enc.setDir(1);
    /*
    if(Serial.available()){
      readVal = Serial.parseInt();  // value from Serial monitor
      if (readVal >= 1000 && readVal <= 3000)
      setPoint = readVal;  
    }
    */

    pid_input =  enc.getRPM();
    myPID.Compute();
    mot.setPwm(pid_output);
  }


  mot.move();
}
