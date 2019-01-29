// encoder class cpp file

#include "encoder.h"

encoder::encoder(){
	GPIO_pin = 0;
	prev_val = 0;
	inst_val = 0;
	edge_count = 0;
	lap = 0;
}

void encoder::setPin(int pin){
	GPIO_pin = pin;
	pinMode(GPIO_pin, INPUT);
}

void encoder::printLaps(){
  Serial.print("Pulsos: ");
  Serial.print(edge_count);
  Serial.print("   Vueltas: ");
  Serial.println(lap);  
}

void encoder::printRPM(){

}

void encoder::measure(){
  inst_val = digitalRead(GPIO_pin);
  if (inst_val != prev_val){
    edge_count++;
    prev_val = inst_val;
  }
  if(edge_count%32 == 0 && edge_count!= 0){
    lap++;
    edge_count = 0;
  }
}

int encoder::getLaps(){
	return lap;
}
