#include <Servo.h>
Servo servo1;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(9);

}

void loop() {
  servo1.writeMicroseconds(2000);
  delay(10000);
  servo1.writeMicroseconds(1000);
  delay(10000);
  // put your main code here, to run repeatedly:

}
