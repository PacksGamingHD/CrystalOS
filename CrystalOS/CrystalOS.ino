#include <LiquidCrystal.h>

// Initialize the library with the pins we're using.
// (Note that you can use different pins if needed.)
// See http://arduino.cc/en/Reference/LiquidCrystal
// for more information:

LiquidCrystal lcd(12,11,5,4,3,2);
const int button1Pin = 7;  // pushbutton 1 pin
const int button2Pin = 8;
int count = 0;
void setup()
{
  // The LiquidCrystal library can be used with many different
  // LCD sizes. We're using one that's 2 lines of 16 characters,
  // so we'll inform the library of that:
  pinMode(button1Pin, INPUT);
  lcd.begin(16, 2);

  // Data sent to the display will stay there until it's
  // overwritten or power is removed. This can be a problem
  // when you upload a new sketch to the Arduino but old data
  // remains on the display. Let's clear the LCD using the
  // clear() command from the LiquidCrystal library:

  lcd.clear();
}

void loop()
{
int button1State;
button1State = digitalRead(button1Pin);
int button2State;
button2State = digitalRead(button2Pin);

lcd.setCursor(0,0);
lcd.print("CrystalOS - v1.0");
lcd.setCursor(0,1);
lcd.print("Blue = Commands");
if (button1State == LOW)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BLUE - Commands");
  lcd.setCursor(0,1);
  lcd.print("YELLOW - Info");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("If you don't");
  lcd.setCursor(0,1);
  lcd.print("press anything");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("you will go home");
  lcd.setCursor(0,1);
  lcd.print("End of help");
  delay(2000);
}
if (button2State == LOW)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CrystalOS - v2.0");
  lcd.setCursor(0,1);
  lcd.print("Made by Sammy");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("j.mp/crystalos");
  lcd.setCursor(0,1);
  lcd.print("Public on GitHub");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Give me credit");
  lcd.setCursor(0,1);
  lcd.print("if you use it");
  delay(2000);
}
}
