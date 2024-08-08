#include <SoftwareSerial.h>
SoftwareSerial gpsSerial(2, 3); // RX, TX
SoftwareSerial gsmSerial(4, 5); // RX, TX

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  gsmSerial.begin(9600);
  delay(1000);
  gsmSerial.println("AT+CGNSPWR=1");
  delay(1000);
}

void loop() {
  if (gpsSerial.available()) {
    String gpsData = gpsSerial.readStringUntil('\n');
    if (gpsData.startsWith("$GPGGA")) {
      gsmSerial.println(gpsData);
    }
  }
  if (gsmSerial.available()) {
    String gsmData = gsmSerial.readStringUntil('\n');
    Serial.println(gsmData);
  }
  delay(1000);
}
