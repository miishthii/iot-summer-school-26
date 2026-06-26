#include<Servo.h>
int buttonState = 0;
const int LED = 3;
void setup()
{
  pinMode(2, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED,LOW);
}

void loop()
{
  buttonState= digitalRead(2);
  Serial.println(buttonState);
  while (buttonState==1){
    digitalWrite(LED, HIGH);
  }
  digitalWrite(LED, LOW);
  delay(10); // Wait for 10 millisecond(s)
}