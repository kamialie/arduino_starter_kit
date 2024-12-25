#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  // Let Arduino know which pin servo motor is attached to
  myServo.attach(9);

  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("potval: ");
  Serial.print(potVal);

  // Map analog input (0-1023) to serve motor angle (0-180)
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}
