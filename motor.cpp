// motor cpp file

#include "motor.h"

motor::motor(){
	pwm_pin = 0;
	IN1_pin = 0;
	IN2_pin = 0;
	pwm = 0;
	dir = 0;
	stop = 0;
}

void motor::setPins(int pwm_PIN, int in1 , int in2){
	pwm_pin = pwm_PIN;
	IN2_pin = in2;
	IN1_pin = in1;
}

void motor::setDir(int d){
	dir = d;
	if (!stop){
		if(!dir){
			digitalWrite(IN1_pin, 1);
			digitalWrite(IN2_pin, 0);
		}
		else{
			digitalWrite(IN1_pin, 0);
			digitalWrite(IN2_pin, 1);
		}		
	}
	else{
		digitalWrite(IN1_pin, 1);
		digitalWrite(IN2_pin, 1);
	}
}

void motor::setPwm(int p){
	pwm = p;
}

void motor::move(){
	analogWrite(pwm_pin, pwm);
}

void motor::stops(){
	stop = 1;
}

void motor::resume(){
	stop = 0;
}

bool motor::getDir(){
	return dir;
}

void motor::toggleDir(){
	dir =! dir;
	if (!stop){
		if(!dir){
			digitalWrite(IN1_pin, 1);
			digitalWrite(IN2_pin, 0);
		}
		else{
			digitalWrite(IN1_pin, 0);
			digitalWrite(IN2_pin, 1);
		}		
	}
	else{
		digitalWrite(IN1_pin, 1);
		digitalWrite(IN2_pin, 1);
	}
}