#include <Servo.h>
Servo servo1;
void setup() {
  // put your setup code here, to run once:
  servo1.attach(9);

}

void loop() {
  servo1.write(0);
  delay(3000);
  servo1.write(90);
  delay(3000);
  // put your main code here, to run repeatedly:

}
