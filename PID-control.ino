#include <PID_v1.h>
#include "encoder.h"

encoder enc;

bool prev = 0;
bool now = 0;
int val = 0;
int lap = 0;

void setup() {
  Serial.begin(1000000);
  enc.setPin(8);
}

void loop() {

  enc.measure();
  enc.printLaps(); 

}
