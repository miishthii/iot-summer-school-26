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

  bool d = digitalRead(dobtn)==LOW;
  bool r = digitalRead(rebtn)==LOW;
  bool m = digitalRead(mibtn)==LOW;
  bool f = digitalRead(fabtn)==LOW;

  int pressed = d+r+m+f;

  if(pressed>=2){
    tone(buzzer,392);}
  else if(d){
    tone(buzzer,262);}
  else if(r){
    tone(buzzer,294);}
  else if(m){
    tone(buzzer,330);}
  else if(f){
    tone(buzzer,349);}
  else{
    noTone(buzzer);}}
