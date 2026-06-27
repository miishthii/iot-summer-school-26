const int led = LED_BUILTIN;
int blink = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Serial Command Interface Ready");}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command == "LED_ON") {
      digitalWrite(led, HIGH);
      Serial.println("LED ON");}

    else if (command == "LED_OFF") {
      digitalWrite(led, LOW);
      Serial.println("LED OFF");}

    else if (command.startsWith("BLINK_")) {
      int times = command.substring(6).toInt();
      if (times >= 1 && times <= 9) {
        for (int i = 0; i < times; i++) {
          digitalWrite(led, HIGH);
          delay(500);
          digitalWrite(led, LOW);
          delay(500);}

        blink += times;
        Serial.print("Blink Count = ");
        Serial.println(blink);}

      else {
        Serial.println("ERROR: Invalid blink count");}}

    else if (command == "STATUS") {

      Serial.print("LED State: ");
      if (digitalRead(led))
        Serial.println("ON");
      else
        Serial.println("OFF");
      Serial.print("Blink Counter: ");
      Serial.println(blink);}

    else if (command == "RESET") {

      blink = 0;
      Serial.println("Blink counter reset");}

    else {
      Serial.println("ERROR: Unknown command");}}}
