/*
 * Author      : Mishthi Chopra
 * Date        : 28 June 2026
 */

const int buzzer = 8;
const int dobtn = 2;
const int rebtn = 3;
const int mibtn = 4;
const int fabtn = 5;

void setup() {
  pinMode(dobtn, INPUT_PULLUP);
  pinMode(rebtn, INPUT_PULLUP);
  pinMode(mibtn, INPUT_PULLUP);
  pinMode(fabtn, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(dobtn) == LOW)
    tone(buzzer,262);
  else if (digitalRead(rebtn) == LOW)
    tone(buzzer,294);
  else if (digitalRead(mibtn) == LOW)
    tone(buzzer,330);
  else if (digitalRead(fabtn) == LOW)
    tone(buzzer,349);
  else
    noTone(buzzer);}
