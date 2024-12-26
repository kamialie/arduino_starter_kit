int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

// This LED will be used to indicate that sensor has finished calibrating
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // Calibrate sensor, find out current high and low
  // millis() function returns how long Arduino has been running since it was
  // last powered on or reset
  while (millis() < 5000) {
    sensorValue = analogRead(A0);

    // Calibrate sensor
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  // Arguments: pin, frequency, duration (milliseconds)
  tone(8, pitch, 20);
  delay(10);
}
