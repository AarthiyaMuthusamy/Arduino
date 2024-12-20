#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
SoftwareSerial mySerial(10, 11);//tx, rx
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

char msg;
char call;
void setup()
{
mySerial.begin(9600); // Setting the baud rate of GSM Module
Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)
Serial.println("GSM SIM900A BEGIN");
Serial.println("Enter character for control option:"); 
Serial.println("h : to disconnect a call");
Serial.println("i : to receive a call");
Serial.println("s : to send message");
Serial.println("r : ReceiveMessage");
Serial.println("c : to make a call");
Serial.println("e : to redial");
Serial.println();
delay(100);
}
void loop()
{
if (Serial.available()>0)
switch(Serial.read())
{
case 's':
SendMessage();
break;
case 'r':
ReceiveMessage();
break;
case 'c':
MakeCall();
break;
case 'h':
HangupCall();
break;
case 'e':
RedialCall();
break;
case 'i':
ReceiveCall();
break;
}
if (mySerial.available()>0)
Serial.write(mySerial.read());
}
void SendMessage()
{
Serial.println("Sending Message");
mySerial.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode
delay(1000); // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"+919345366672\"\r"); // Replace x with mobile number +91
delay(1000);
mySerial.println("sim900a sms");// The SMS text you want to send
delay(100);
mySerial.println((char)26);// ASCII code of CTRL+Z
delay(1000);
}
void ReceiveMessage()
{
Serial.println("Received Message");
mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
delay(1000);
if (mySerial.available()>0)
{
msg=mySerial.read();
Serial.print(msg);
}
}
void MakeCall()
{
mySerial.println("ATD+919345366672;"); // ATDxxxxxxxxxx; -- watch out here for semicolon at the end!!
Serial.println("Calling "); // print response over serial port
delay(5000);
}
void HangupCall()
{
mySerial.println("ATH");
Serial.println("Hangup Call");
delay(1000);
}
void ReceiveCall()
{
mySerial.println("ATA");
Serial.println("Received Call");
delay(1000);
{
call=mySerial.read();
Serial.print(call);
}
}
void RedialCall()
{
mySerial.println("ATDL");
Serial.println("Redialing");
delay(1000);
}
