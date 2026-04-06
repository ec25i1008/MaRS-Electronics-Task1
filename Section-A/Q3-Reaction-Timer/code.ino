int ledPin = 8;
int buttonPin = 2;

unsigned long startTime;
unsigned long reactionTime;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Reaction Timer Ready!");
}

void loop() {
  // wait random time before turning LED on
  int waitTime = random(2000, 5000);
  delay(waitTime);

  digitalWrite(ledPin, HIGH);
  startTime = millis();

  // wait until button pressed
  while (digitalRead(buttonPin) == HIGH) {
    // waiting...
  }

  reactionTime = millis() - startTime;

  digitalWrite(ledPin, LOW);

  Serial.print("Reaction Time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");

  delay(3000);
}
