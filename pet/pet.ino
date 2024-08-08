      
#include <Servo.h>
#define trigPin 4
#define echoPin 5 

int pos = 0;

Servo servo_9;

void setup()
{
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

int duration = pulseIn(echoPin, HIGH);

int distance = (duration/2) / 29.1;
  if (distance < 30) //if pet reach food less than 30cm then servo motor will open knob
{
servo_9.attach(9, 500, 2500);
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(10); // Wait for 10 millisecond(s)
  }
  for (pos = 180; pos >=0; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(1); // Wait for 1 millisecond(s)
  }
 

}
else {

} 
 delay(100); // Wait for 50 Seconds

}
