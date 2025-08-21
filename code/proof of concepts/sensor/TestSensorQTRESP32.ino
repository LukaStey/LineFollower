/*
   QTR-8A sensor uitlezen met ESP32
   Sluit de 8 sensoren aan op de volgende pinnen:
   S0 -> GPIO36
   S1 -> GPIO39
   S2 -> GPIO34
   S3 -> GPIO35
   S4 -> GPIO32
   S5 -> GPIO33
   S6 -> GPIO25
   S7 -> GPIO26
*/

#define NUM_SENSORS 8

int sensorPins[NUM_SENSORS] = {36, 39, 25, 34, 35, 26, 32, 33};
int sensorValues[NUM_SENSORS];

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("QTR-8A Test gestart");
}

void loop() {
  // Lees alle sensoren
  for (int i = 0; i < NUM_SENSORS; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }

  // Print de waardes
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(sensorValues[i]);
    Serial.print("\t");
  }
  Serial.println();

  delay(100);  // iets vertraging
}