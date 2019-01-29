// encoder class header file


#include "Arduino.h"

class encoder{
private:
	int GPIO_pin;
	bool prev_val;
	bool inst_val;
	int edge_count;
	int lap;

public:
	encoder();
	void setPin(int pin);
	void printLaps();
	void printRPM();
	void measure();
	int getLaps();
};
