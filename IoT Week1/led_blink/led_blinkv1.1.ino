/*
 * Author      : Mishthi Chopra
 * Date        : 28 June 2026
 */

int blinkcount = 0;

void setup(){
  pinMode(13, OUTPUT);
  Serial.begin(9600);}

void loop(){
  digitalWrite(13, HIGH);
  delay(500);

  digitalWrite(13, LOW);
  delay(500);

  blinkcount++;

  Serial.print("Blink count: ");
  Serial.println(blinkcount);}
