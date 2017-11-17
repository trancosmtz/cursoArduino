#include <Servo.h>

Servo motor;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  motor.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
motor.write(0);
delay(1000);

motor.write(90);
delay(1000);

motor.write(180);
delay(1000);
}
