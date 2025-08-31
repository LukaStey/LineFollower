
#define NUM_SENSORS 8
int sensorPins[NUM_SENSORS] = {32, 33, 34, 35, 36, 39, 25, 26};
int sensorValues[NUM_SENSORS];

// Motor pins
#define AIN1 12
#define AIN2 13
#define BIN1 14
#define BIN2 27
#define STBY 4  // H-brug STBY pin

void setup() {
  Serial.begin(115200);

  // Motor pinnen instellen
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH); // H-brug inschakelen

  Serial.println("Line Follower gestart!");
}

void loop() {
  int position = readSensors();
  int error = position - 3500;

  // Digitale P-controller: stuur bochten
  if(error > 200){       // lijn naar links
    // bocht naar rechts
    digitalWrite(AIN1, HIGH);  // linkermotor vooruit
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);   // rechtermotor stoppen
    digitalWrite(BIN2, LOW);
  }
  else if(error < -200){ // lijn naar rechts
    // bocht naar links
    digitalWrite(AIN1, LOW);   // linkermotor stoppen
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH);  // rechtermotor vooruit
    digitalWrite(BIN2, LOW);
  }
  else{
    // rechtdoor
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  }

  delay(10);
}

// Functie om alle QTR sensoren te lezen
int readSensors() {
  long avg = 0;
  int sum = 0;

  for (int i = 0; i < NUM_SENSORS; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
    int value = map(sensorValues[i], 0, 4095, 0, 1000);  // schalen naar 0-1000
    avg += (long)value * (i * 1000);
    sum += value;
  }

  if (sum > 0)
    return avg / sum;
  else
    return 3500; // geen lijn → ga rechtdoor
}
