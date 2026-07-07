// =====================================
// Smart Street Lighting System
// ESP32 + LDR + PIR
// =====================================

#define LDR_PIN 34
#define PIR_PIN 27
#define LED_PIN 25

void setup() {

  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("Smart Street Lighting System Started");
}

void loop() {

  int lightValue = analogRead(LDR_PIN);
  bool motion = digitalRead(PIR_PIN);

  bool streetLight = false;

  // Night condition
  if (lightValue < 1800) {

    if (motion) {
      streetLight = true;
    }

  }

  digitalWrite(LED_PIN, streetLight);

  Serial.println("-----------------------------");
  Serial.print("LDR Value : ");
  Serial.println(lightValue);

  Serial.print("Motion : ");
  Serial.println(motion ? "Detected" : "Not Detected");

  Serial.print("Street Light : ");
  Serial.println(streetLight ? "ON" : "OFF");

  if (lightValue >= 1800)
    Serial.println("Status : Daytime");

  else
    Serial.println("Status : Night");

  delay(1000);
}
