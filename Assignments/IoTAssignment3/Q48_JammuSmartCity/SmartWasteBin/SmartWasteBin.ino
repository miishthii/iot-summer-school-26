// ======================================
// Smart Waste Bin Monitoring
// ESP32 + HC-SR04
// ======================================

#define TRIG_PIN 5
#define ECHO_PIN 18

#define GREEN_LED 25
#define YELLOW_LED 26
#define RED_LED 27

float getDistance() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.034 / 2;

  return distance;
}

void setup() {

  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  Serial.println("Smart Waste Bin Monitoring");
}

void loop() {

  float distance = getDistance();

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  String status;

  // Bin nearly empty
  if (distance > 20) {

    status = "EMPTY";

    digitalWrite(GREEN_LED, HIGH);

  }

  // Bin half full
  else if (distance > 10) {

    status = "HALF FULL";

    digitalWrite(YELLOW_LED, HIGH);

  }

  // Bin full
  else {

    status = "FULL";

    digitalWrite(RED_LED, HIGH);

  }

  Serial.println("----------------------");

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Bin Status : ");
  Serial.println(status);

  delay(2000);
}
