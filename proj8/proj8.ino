const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int previousSwitchState = 0;
int led = 2;
long interval = 1000 * 5; // milliseconds

bool animation = false;
unsigned long animationPreviousTime = 0;
int animationInterval = 1000 * 1 / 8;

void setup() {
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }

  pinMode(switchPin, INPUT);
  // Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();

  if (animation == false && currentTime - previousTime > interval) {
    previousTime = currentTime; // reset timer
    digitalWrite(led, HIGH);
    led++;
    if (led == 8) { // if all LEDs are on
      animation = true;
      led = 0;
    }
  }

  if (animation == true && currentTime - animationPreviousTime > animationInterval) {
    animationPreviousTime = currentTime;
    digitalWrite(led++ % 6 + 2, LOW);
    digitalWrite(led % 6 + 2, HIGH);
  }
  
  switchState  = digitalRead(switchPin);
  // Serial.print("switchState: ");
  // Serial.println(switchState);
  if (switchState != previousSwitchState) {
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }

    led = 2;
    previousTime = currentTime; // reset timer
    animation = false;
  }

  previousSwitchState = switchState;
  // delay(100);
}
