
#define IN1 6
#define IN2 7
#define pwm 9
#define del 10
#define d 200
#define m 35

void setup() {
  pinMode(IN1 , OUTPUT);
  pinMode(IN2 , OUTPUT);
  pinMode(pwm , OUTPUT);

}

void loop() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  for(int i = m; i < 255; i++){
    analogWrite(pwm, i);
    delay(del);
  }

  delay(d);

  for(int i = 255; i > m; i--){
    analogWrite(pwm, i);
    delay(del);
  }

  delay(d);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  for(int i = m; i < 255; i++){
    analogWrite(pwm, i);
    delay(del);
  }

  delay(d);

  for(int i = 255; i > m; i--){
    analogWrite(pwm, i);
    delay(del);
  }
  delay(d);

}
