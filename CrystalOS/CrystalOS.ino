/*
CrystalOS - Made by PacksGamingHD
*/

/** Code Guide
 * lcd.print(""); - Print a message to the LCD
 * delay() - What number you put there, it will delay the code *IMPORTANT - YOU MUST PUT THIS AFTER EVERYTIME YOU WANT TO PUT SOMETHING NEW*
 * lcd.clear(); - Clears the LCD
 * if (button1State == LOW) - When you push button 1 then it will do what you put in the code
 * lcd.setCursor(0,0); - Sets the cursor to the first line
 * lcd.setCursor(0,1); - Sets the cursor to the second line
 * Find all of the commands here: http://arduino.cc/en/Reference/LiquidCrystal
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int button1Pin = 7;
const int button2Pin = 8;
int count = 0;
void setup()
{
  pinMode(button1Pin, INPUT);
  lcd.begin(16, 2);
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
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Updates:");
  lcd.setCursor(0,1);
  lcd.print("- Add updates");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("On GitHub");
  lcd.setCursor(0,1);
  lcd.print("- Updates to OS");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("- Shorten stuff");
  lcd.print("- Create OS")
}
}
