#include<Servo.h>
int rows[4] = {1,2,3,4};
int cols[4] = {5,6,7,8};

int M[4][4] = {
  {1, 0, 0, 1},
  {1, 1, 1, 1},
  {1, 1, 1, 1},
  {1, 0, 0, 1}};
int C[4][4] = {
  {1, 1, 1, 1},
  {1, 0, 0, 0},
  {1, 0, 0, 0},
  {1, 1, 1, 1}};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(cols[i], OUTPUT);
    digitalWrite(rows[i], LOW);
    digitalWrite(cols[i], HIGH);}}

void loop() {
  for (int r = 0; r < 4; r++) {
    digitalWrite(rows[r], HIGH);
    for (int c = 0; c < 4; c++) {
      if (M[r][c] == 1)
        digitalWrite(cols[c], LOW);
      else
        digitalWrite(cols[c], HIGH);}
    delay(10);
    digitalWrite(rows[r], LOW);
    for (int c = 0; c < 4; c++)
      digitalWrite(cols[c], HIGH);}
delay(1000);
for (int r = 0; r < 4; r++) {
    digitalWrite(rows[r], HIGH);
    for (int c = 0; c < 4; c++) {
      if (C[r][c] == 1)
        digitalWrite(cols[c], LOW);
      else
        digitalWrite(cols[c], HIGH);}
    delay(10);
    digitalWrite(rows[r], LOW);
    for (int c = 0; c < 4; c++)
      digitalWrite(cols[c], HIGH);}
delay(1000);}
