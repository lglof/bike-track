#include <Arduino.h>

volatile byte revolutions;
unsigned int rpm;
unsigned long timeold;
const byte interruptPin = 2;

void magnet_detect();

void setup() {
  Serial.begin(9600);
  Serial.print("Hello World!");
  // pinMode(2, INPUT);

  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), magnet_detect, RISING);
  revolutions = 0;
  rpm = 0;
  timeold = 0;
}

void loop() {
  Serial.println(revolutions);

  if (revolutions >= 20) { 
    rpm = 30*1000/(millis() - timeold)*revolutions;
    timeold = millis();
    revolutions = 0;
    Serial.println("rpm");
    Serial.println(rpm, DEC);
  } 
  delay(1000);
}

void magnet_detect() {
  revolutions++;
}