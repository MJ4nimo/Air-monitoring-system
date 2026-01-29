#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(8, 2, 4, 5,6 , 7);

// Pin definitions
const int gasDigitalPin = 3;   // MQ sensor DO
const int gasAnalogPin  = A0;  // MQ sensor AO

const int redLED   = 12;
const int greenLED = 10;
const int buzzer   = 13;

void setup() {
  pinMode(gasDigitalPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Gas Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  int gasState = digitalRead(gasDigitalPin); // LOGIC STATE
  int gasValue = analogRead(gasAnalogPin);   // Sensor reading

  lcd.setCursor(0, 0);
  lcd.print("Gas Value: ");
  lcd.print(gasValue);
  lcd.print("   "); // clear leftovers

  if (gasState == HIGH) {
    // BAD GAS DETECTED
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("Status: DANGER ");
  } 
  else {
    // GOOD CONDITION
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Status: SAFE   ");
  }

  delay(500);
}
