// motor class header file

#include "Arduino.h"

class motor{
private:
	int pwm_pin;
	int IN1_pin;
	int IN2_pin;
	int pwm;
	bool dir;	// 1 clockwise, 0 counterclockwise
	bool stop;	// when true, the motor stops

public:
	motor();
	void setPins(int pwm_pin, int IN1_pin, int IN2_pin);
	void setDir(int d);
	void setPwm(int pwm);
	void move();
	void stops();
	void resume();
	bool getDir();
	void toggleDir();
};