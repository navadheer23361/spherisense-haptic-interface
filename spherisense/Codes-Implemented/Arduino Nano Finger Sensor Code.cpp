/*
 * Arduino Nano Finger Sensor Interface
 * Reads analog finger sensors and sends data over Serial
 * to ESP32.
 */

const int fingerPins[5] = {A0, A1, A2, A3, A4};

void setup() {

  Serial.begin(115200);

  for (int i = 0; i < 5; i++) {
    pinMode(fingerPins[i], INPUT);
  }

  Serial.println("Finger sensor module started");
}

void loop() {

  int values[5];

  for (int i = 0; i < 5; i++) {
    values[i] = analogRead(fingerPins[i]);
  }

  Serial.print("F:");

  for (int i = 0; i < 5; i++) {

    Serial.print(values[i]);

    if (i < 4)
      Serial.print(",");
  }

  Serial.println();

  delay(50);
}