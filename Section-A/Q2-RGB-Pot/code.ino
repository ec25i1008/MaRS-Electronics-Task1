// Pins
int potPin = A0;
int blinkLED = 6;

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

int potValue;
int blinkDelay;

void setup() {
  pinMode(blinkLED, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // read potentiometer (0 - 1023)
  potValue = analogRead(potPin);

  // convert to 0 - 255 for RGB
  int brightness = map(potValue, 0, 1023, 0, 255);

  // change RGB colour
  analogWrite(redPin, brightness);
  analogWrite(greenPin, 255 - brightness);
  analogWrite(bluePin, brightness / 2);

  // change blinking speed (fast ↔ slow)
  blinkDelay = map(potValue, 0, 1023, 100, 1000);

  digitalWrite(blinkLED, HIGH);
  delay(blinkDelay);
  digitalWrite(blinkLED, LOW);
  delay(blinkDelay);
}
