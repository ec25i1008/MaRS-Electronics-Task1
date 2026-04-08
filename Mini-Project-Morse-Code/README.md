Mini Project 1: Automatic Plant Watering System

Objective: To design an Arduino-based system that automatically waters plants by monitoring soil moisture levels.

Components Used:
Arduino UNO
Soil Moisture Sensor
DC Motor (Water Pump)
TIP120 Transistor
Flyback Diode
LED
220Ω Resistor
1kΩ Resistor
Breadboard & Jumper wires

Working Principle:
The soil moisture sensor measures moisture level.
Arduino reads analog values (0–1023).
Based on moisture level:
  Wet soil → Pump OFF
  Medium moisture → Warning LED ON
  Dry soil → Pump ON (watering starts)

Code:
// Pin connections
int sensorPin = A0;   // Soil moisture sensor connected to Analog Pin A0
int motorPin  = 8;    // Transistor (motor pump control) connected to Pin 8
int ledPin    = 13;   // Warning LED connected to Pin 13

void setup()
{
  // Set motor and LED as OUTPUT devices
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Start serial monitor to see moisture values
  Serial.begin(9600);
}

void loop()
{
  // Read soil moisture value (0 to 1023)
  int moistureValue = analogRead(sensorPin);

  // Print value in Serial Monitor (for testing)
  Serial.print("Moisture Level: ");
  Serial.println(moistureValue);

  // ---------- CONDITION 1 : SOIL IS DRY ----------
  // If value is HIGH → soil is dry → turn pump ON
  if (moistureValue > 800)
  {
    digitalWrite(motorPin, HIGH);   // Turn water pump ON
    digitalWrite(ledPin, HIGH);     // Turn warning LED ON
    Serial.println("Soil is DRY → Water pump ON");
  }

  // ---------- CONDITION 2 : SOIL IS MEDIUM ----------
  // If value is medium → no watering but LED ON as warning
  else if (moistureValue > 500)
  {
    digitalWrite(motorPin, LOW);    // Pump OFF
    digitalWrite(ledPin, HIGH);     // LED ON
    Serial.println("Soil is OK → Monitoring...");
  }

  // ---------- CONDITION 3 : SOIL IS WET ----------
  // If value is LOW → soil wet → everything OFF
  else
  {
    digitalWrite(motorPin, LOW);    // Pump OFF
    digitalWrite(ledPin, LOW);      // LED OFF
    Serial.println("Soil is WET → Pump OFF");
  }

  // Wait half a second before next reading
  delay(500);
}

Moisture Thresholds:
| Moisture Value | Condition | Action   |
| -------------- | --------- | -------- |
| 0 – 500        | Wet soil  | Pump OFF |
| 500 – 800      | Medium    | LED ON   |
| 800 – 1023     | Dry soil  | Pump ON  |

Real-World Applications:
  Smart agriculture
  Home gardening automation
  Greenhouse monitoring systems
  Water conservation systems

Mini Project 2: Arduino-Morse-Code-Encoder

Objective: This project converts text entered in the Arduino Serial Monitor into Morse code and outputs it using an LED and a Piezo buzzer.

Components Used:
  Arduino UNO
  LED
  220Ω Resistor
  Piezo Buzzer
  Breadboard & Jumper Wires
   
Working:
  Accepts real-time text input via Serial Monitor
  Converts A–Z alphabets into Morse code
  Outputs Morse as LED flashes and buzzer beeps
  Prints Morse translation in Serial Monitor

CODE:
int ledPin = 8;
int piezoPin = 9;

int dotTime = 200;
int dashTime = 600;
int symbolGap = 200;
int letterGap = 600;
int wordGap = 1500;

// Morse table A-Z
String morse[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

void signalOn(int duration)
{
  digitalWrite(ledPin, HIGH);
  tone(piezoPin, 1000);
  delay(duration);
  digitalWrite(ledPin, LOW);
  noTone(piezoPin);
  delay(symbolGap);
}

void dot(){ signalOn(dotTime); }
void dash(){ signalOn(dashTime); }

void playMorse(char c)
{
  if(c >= 'A' && c <= 'Z')
  {
    String code = morse[c-'A'];
    Serial.print(code);   //  PRINT MORSE

    for(int i=0; i<code.length(); i++)
    {
      if(code[i] == '.') dot();
      else dash();
    }
    Serial.print(" ");    // space between letters
    delay(letterGap);
  }
}

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Type text:");
}

void loop()
{
  if(Serial.available())
  {
    String text = Serial.readStringUntil('\n');
    text.toUpperCase();

    Serial.print("Morse: ");

    for(int i=0; i<text.length(); i++)
    {
      if(text[i] == ' ')
      {
        Serial.print("   "); // word gap
        delay(wordGap);
      }
      else
      {
        playMorse(text[i]);
      }
    }

    Serial.println(); // new line after message
  }
}

Applications:
 Emergency communication
 Learning Morse code
 Embedded systems practice
