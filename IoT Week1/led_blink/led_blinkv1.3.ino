/*
Author: Mishthi Chopra
Date: 27 June 2026
Description: LED blink program with potentiometer speed control and serial blink counter.
*/

// Updated potentiometer mapping.

int led = 13;
int pot = A0;
int blinkcount = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);}

void loop() {

  int sensorval = analogRead(pot);
  int delaytime = map(sensorval, 0, 1023, 100, 1000);

  digitalWrite(led, HIGH);
  delay(delaytime);

  digitalWrite(led, LOW);
  delay(delaytime);

  blinkcount++;

  Serial.print("Blink count: ");
  Serial.println(blinkcount);}
