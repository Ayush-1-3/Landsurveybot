#include <SoftwareSerial.h>

SoftwareSerial bluetooth(3, 2); // RX, TX
char t;

#define MLa 8    // Left motor 1st pin
#define MLb 9    // Left motor 2nd pin
#define MRa 10   // Right motor 1st pin
#define MRb 11   // Right motor 2nd pin
#define LEDR 6   // The pin the REAR LED is connected to
#define BUZ 5    // The pin the BUZZER is connected to
#define LEDF 7   // The pin the FRONT LED is connected to

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(MLa, OUTPUT);  // Left motors forward
  pinMode(MLb, OUTPUT);  // Left motors reverse
  pinMode(MRa, OUTPUT);  // Right motors forward
  pinMode(MRb, OUTPUT);  // Right motors reverse
  pinMode(LEDF, OUTPUT); // Declare the FRONT LED as an output
  pinMode(LEDR, OUTPUT); // Declare the REAR LED as an output
  pinMode(BUZ, OUTPUT);  // Declare the BUZZER as an output
}

void loop() {
  if (bluetooth.available() > 0) {
    t = bluetooth.read();
    Serial.println(t);
  }
  
  switch (t) {
    case 'F':  // Move forward
      digitalWrite(MLa, HIGH);
      digitalWrite(MLb, LOW);
      digitalWrite(MRa, HIGH);
      digitalWrite(MRb, LOW);
      digitalWrite(LEDF, HIGH);
      delay(10);
      digitalWrite(LEDF, LOW);
      break;
      
    case 'B':  // Move reverse
      digitalWrite(MLa, LOW);
      digitalWrite(MLb, HIGH);
      digitalWrite(MRa, LOW);
      digitalWrite(MRb, HIGH);
      digitalWrite(LEDR, HIGH);
      delay(10);
      digitalWrite(LEDR, LOW);
      break;
      
    case 'L':  // Turn left
      digitalWrite(MLa, HIGH);
      digitalWrite(MLb, LOW);
      digitalWrite(MRa, LOW);
      digitalWrite(MRb, LOW);
      break;
      
    case 'R':  // Turn right
      digitalWrite(MLa, LOW);
      digitalWrite(MLb, LOW);
      digitalWrite(MRa, HIGH);
      digitalWrite(MRb, LOW);
      break;
      
    case 'V':  // Buzzer ON
      digitalWrite(BUZ, HIGH);
      break;
      
    case 'v':  // Buzzer OFF
      digitalWrite(BUZ, LOW);
      break;
      
    case 'W':  // FRONT LED ON
      digitalWrite(LEDF, HIGH);
      break;
      
    case 'w':  // FRONT LED OFF
      digitalWrite(LEDF, LOW);
      break;
      
    case 'U':  // REAR LED ON
      digitalWrite(LEDR, HIGH);
      break;
      
    case 'u':  // REAR LED OFF
      digitalWrite(LEDR, LOW);
      break;
      
    case 'S':  // STOP
      digitalWrite(MLa, LOW);
      digitalWrite(MLb, LOW);
      digitalWrite(MRa, LOW);
      digitalWrite(MRb, LOW);
      break;
  }
}