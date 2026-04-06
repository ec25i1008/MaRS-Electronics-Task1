// C++ code
//
// LED pins
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;

// blink intervals
unsigned long interval1 = 500;
unsigned long interval2 = 1000;
unsigned long interval3 = 1500;

// store last time each LED blinked
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

// LED states
bool ledState1 = LOW;
bool ledState2 = LOW;
bool ledState3 = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // LED 1 (500ms)
  if (currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;
    ledState1 = !ledState1;
    digitalWrite(led1, ledState1);
  }

  // LED 2 (1000ms)
  if (currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;
    ledState2 = !ledState2;
    digitalWrite(led2, ledState2);
  }

  // LED 3 (1500ms)
  if (currentMillis - previousMillis3 >= interval3) {
    previousMillis3 = currentMillis;
    ledState3 = !ledState3;
    digitalWrite(led3, ledState3);
  }
}
