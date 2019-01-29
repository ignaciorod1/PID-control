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
	void set_pins(int pwm_pin, int IN1_pin, int IN2_pin);
	void set_dir(int d);
	void set_pwm(int pwm);
	void move();
	void stops();
	void resume();
};