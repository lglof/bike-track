#include <Arduino.h>

volatile byte revolutions;
unsigned int rpm;
unsigned long timeold;
const byte interruptPin = 2;
float wheel_diameter = 0.72; // this is in m
float wheel_circumference = PI * wheel_diameter;
float total_dist;

void magnet_detect();

void setup() {
  Serial.begin(9600);
  Serial.println("Hello World!");

  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), magnet_detect, RISING);
  revolutions = 0;
  rpm = 0;
  timeold = 0;
  total_dist = 0;

  Serial.println("variable check");
  Serial.println(wheel_circumference);
  Serial.println(wheel_diameter);
}

void loop() {
  if (revolutions >= 5) { 
    rpm = 30*1000/(millis() - timeold)*revolutions;
    timeold = millis();
    revolutions = 0;
    Serial.println("rpm");
    Serial.println(rpm, DEC);
    Serial.println("total dist");
    Serial.println(total_dist);
  } 
  delay(1000);
}

void magnet_detect() {
  Serial.println("triggered");
  revolutions++;
  total_dist += wheel_circumference;
}