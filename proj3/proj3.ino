const int sensorPin = A0;
const float baselineTemp = 22.0;

void setup() {
  // Open serial port: connects Arduino to computer, thus, providing analog
  // data. Input 9600 is the speed of communication, 9600 bits per second.
  Serial.begin(9600);

  for(int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin); // value between 0 and 1023 represents voltage from 0 to 5
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  // Convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // Substract offset since sensor can read temperatures below 0
  // Vout = Tcoef * Tambient + Vzero
  float temperature = (voltage - 0.5) * 100;
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  if (temperature < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  // Sensor can read data only so often, reading more often might produce
  // erratic data
  delay(250);
}
