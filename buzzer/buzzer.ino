
const int buzzzerpin = 9;
void setup(){

  pinMode(buzzzerpin,OUTPUT);

  
}
void loop(){

  tone(buzzzerpin,500,500);
  delay(1000);
}
