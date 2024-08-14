#include <Arduino.h>

volatile byte revolutions;
unsigned int rpm;
unsigned long timeold;

int myFunction(int, int);
void magnet_detect();

void setup() {
  Serial.begin(9600);
  Serial.print("Hello World!");
  attachInterrupt(0, magnet_detect, RISING);
  revolutions = 0;
  rpm = 0;
  timeold = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(revolutions);
  if (revolutions >= 20) { 
    rpm = 30*1000/(millis() - timeold)*revolutions;
    timeold = millis();
    revolutions = 0;
    Serial.println(rpm,DEC);
  } 
  delay(1000);
}

void magnet_detect() {
  revolutions++;
  Serial.println("detect");
}