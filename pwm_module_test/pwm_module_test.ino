
#define IN1 6
#define IN2 7
#define pwm 9

void setup() {
  pinMode(IN1 , OUTPUT);
  pinMode(IN2 , OUTPUT);
  pinMode(pwm , OUTPUT);

}

void loop() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  for(int i = 0; i < 255; i++){
    analogWrite(pwm, i);
    delay(100);
  }

  delay(1000);

  for(int i = 255; i > 0; i--){
    analogWrite(pwm, i);
    delay(100);
  }

  delay(1000);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  for(int i = 0; i < 255; i++){
    analogWrite(pwm, i);
    delay(100);
  }

  delay(1000);

  for(int i = 255; i > 0; i--){
    analogWrite(pwm, i);
    delay(100);
  }

}
