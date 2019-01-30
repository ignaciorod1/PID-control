// encoder class header file


#include "Arduino.h"

class encoder{
private:
	int GPIO_pin;
	bool prev_val;
	bool inst_val;
	int edge_count;
	int lap;
	bool dir;
	int RPM;
	unsigned long tbg;
	unsigned long a;


public:
	encoder();
	void setPin(int pin);
	void printLaps();
	void printRPM();
	void measure();
	void setDir(bool d);
	bool getDir();
	int getLaps();
	void printDir();
	int getRPM();
};
