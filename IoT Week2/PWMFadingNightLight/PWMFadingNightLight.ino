/*
 * Author      : Mishthi Chopra
 * Date        : 28 June 2026
 */

const int ledPin = 9;
const int buttonPin = 2;
const int ldrPin = A0;

int mode = 1;
int threshold = 500;     // Adjust if required

bool lastButtonState = HIGH;
bool currentButtonState;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Automatic PWM Night Light");
  Serial.println("Mode 1 : Slow Breathing");}

void loop() {

  // ---------- Button ----------
  currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    mode++;
    if (mode > 3)
      mode = 1;
    printMode();
    delay(250);}
  lastButtonState = currentButtonState;

  // ---------- LDR ----------
  int light = analogRead(ldrPin);

  // Bright -> LED OFF
  if (light > threshold) {
    analogWrite(ledPin, 0);
    return;}

  // Dark -> Run Selected Mode
  if (mode == 1)
    slowBreathing();
  else if (mode == 2)
    fastPulse();
  else
    sosPattern();}

void printMode() {
  if (mode == 1)
    Serial.println("Mode 1 : Slow Breathing");
  else if (mode == 2)
    Serial.println("Mode 2 : Fast Pulse");
  else
    Serial.println("Mode 3 : SOS Pattern");}

// ===============================
// Slow Breathing (~3 sec cycle)
// ===============================
void slowBreathing() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(6);
    if (modeChanged()) return;}
  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(6);
    if (modeChanged()) return;}}

// ===============================
// Fast Pulse (~0.5 sec cycle)
// ===============================
void fastPulse() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(1);
    if (modeChanged()) return;}
  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(1);
    if (modeChanged()) return;}}

// ===============================
// SOS Pattern
// ===============================
void sosPattern() {
  dot();
  dot();
  dot();

  dash();
  dash();
  dash();

  dot();
  dot();
  dot();

  delay(1000);}

// ===============================
// Dot
// ===============================
void dot() {
  analogWrite(ledPin, 255);
  delay(200);
  analogWrite(ledPin, 0);
  delay(200);
  modeChanged();}

// ===============================
// Dash
// ===============================
void dash() {
  analogWrite(ledPin, 255);
  delay(600);
  analogWrite(ledPin, 0);
  delay(200);
  modeChanged();}

// ===============================
// Check Button During Animation
// ===============================
bool modeChanged() {
  currentButtonState = digitalRead(buttonPin);
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    mode++;
    if (mode > 3)
      mode = 1;
    printMode();
    delay(250);
    lastButtonState = currentButtonState;
    analogWrite(ledPin, 0);
    return true;}
  lastButtonState = currentButtonState;
  return false;}
