#include <Servo.h>


int servopin = 3;

Servo servo1;

void setup() {
  // put your setup code here, to run once:

servo1.attach(servopin);





}

void loop() {
  //  put your main code here, to run repeatedly:

  servo1.write(0);

  delay(1000);
  servo1.write(90);
  delay(1000);
    servo1.write(180);
      delay(1000);


}
