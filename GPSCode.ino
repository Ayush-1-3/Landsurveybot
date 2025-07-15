// Arduino Nano GPS code//
#include <SD.h>
#include <SPI.h>
#include <SoftwareSerial.h> 
#include "TinyGPS++.h"

const int ledPin = 9;
int programStatus = 0;

File file;
String filename = "log.csv";  // Consistent filename
int id = 0;

TinyGPSPlus gps;
SoftwareSerial SoftSerial(2, 3); 

void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  SoftSerial.begin(9600);
  Serial.begin(9600);
  
  programStatus = initializeSD();
  delay(3000); 
  
  if (programStatus == 1) {
    file = SD.open(filename, FILE_WRITE);
    if (file) {
      writeHeaderToFile();
      file.close();
    } else {
      programStatus = 0;
    }
  }
}

void loop()
{
  // Read GPS data
  while (SoftSerial.available() > 0) {
    gps.encode(SoftSerial.read());
  }
  
  // Status LED for SD card initialization failure
  if (programStatus == 0) {
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(300);
    return;
  }
  
  // If we have valid GPS data
  if (gps.location.isValid() && gps.date.isValid() && gps.time.isValid()) {
    blinkQuickly();
    
    String latitude = String(gps.location.lat(), 6);
    String longitude = String(gps.location.lng(), 6);
    
    // Format date and time with leading zeros
    String dayString = (gps.date.day() < 10) ? "0" + String(gps.date.day()) : String(gps.date.day());
    String monthString = (gps.date.month() < 10) ? "0" + String(gps.date.month()) : String(gps.date.month());
    String hourString = (gps.time.hour() < 10) ? "0" + String(gps.time.hour()) : String(gps.time.hour());
    String minuteString = (gps.time.minute() < 10) ? "0" + String(gps.time.minute()) : String(gps.time.minute());
    String secondString = (gps.time.second() < 10) ? "0" + String(gps.time.second()) : String(gps.time.second());
    
    id++;
    String entry = String(id) + "," + 
                  dayString + "/" + monthString + "/" + String(gps.date.year()) + "," + 
                  hourString + ":" + minuteString + ":" + secondString + "," + 
                  latitude + "," + longitude;
    
    Serial.println(entry);
    
    file = SD.open(filename, FILE_WRITE);
    if (file) {
      file.println(entry);
      file.close();
    } else {
      programStatus = 0; // Mark SD card as failed
    }
    
    delay(5000); // Wait 5 seconds before next reading
  }
  else {
    // Slow blink when waiting for GPS lock
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}

int initializeSD()
{
  Serial.println("Initializing SD card...");
  pinMode(10, OUTPUT);

  if (SD.begin(10)) {
    Serial.println("SD card is ready to use.");
    return 1;
  } else {
    Serial.println("SD card initialization failed");
    return 0;
  }
}

void writeHeaderToFile()
{
  if (file) {
    file.println("Id,Date,Time,Latitude,Longitude");
  }
}

void blinkQuickly()
{
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
}