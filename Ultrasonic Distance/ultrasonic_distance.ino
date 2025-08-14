// Basic program for Ultrasonic Sensor HC-SR04
// Author: Hasham Muhammad
// HC-SR04 Ultrasound Sensor
// Connections: 5V -> 5V, GND -> GND, D2 -> Echo, D3 -> Trig
// You may need to install libraries via "Tools -> Manage Libraries"
// Revision: 22.6.24

#include <SoftwareSerial.h>

// Pin definitions
#define TRIGGER_PIN 3  // Arduino pin connected to HC-SR04 Trig
#define ECHO_PIN 2     // Arduino pin connected to HC-SR04 Echo

// SoftwareSerial for communication
SoftwareSerial ardunano(11, 12);

void setup() {
  // Initialize pins
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(TRIGGER_PIN, LOW); // Ensure trigger is LOW

  // Initialize Serial communication
  Serial.begin(9600);
  ardunano.begin(9600);
}

void loop() {
  int tof = getToF(); // Read time of flight
  Serial.print(tof, DEC);
  Serial.write('\n'); // Send newline
  delay(1000);        // Wait 1 second
}

/* Function: getToF
   Returns the time of flight (echo duration) in microseconds
*/
int getToF() {
  long time = 0;

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(3);

  noInterrupts();            // Disable interrupts for precise timing
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(20);     // Trigger pulse of 20 microseconds
  digitalWrite(TRIGGER_PIN, LOW);

  time = pulseIn(ECHO_PIN, HIGH); // Measure echo time
  interrupts();                    // Re-enable interrupts

  return time;
}
