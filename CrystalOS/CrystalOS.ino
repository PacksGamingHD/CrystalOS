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
const int temperaturePin = 0;
int count = 0;
void start()
{
  delay(2000);
  lcd.setCursor(0,0);
  lcd.clear();
}
void start1()
{
  delay(2000);
  lcd.setCursor(0,1);
  lcd.clear();
} 
void setup()
{
pinMode(button1Pin, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
  lcd.setCursor(0,0);
lcd.print("O");
lcd.setCursor(0,1);
lcd.print("Starting up");
delay(1500);
lcd.setCursor(0,0);
lcd.print("O O");
lcd.setCursor(0,1);
lcd.print("Loading /home");
delay(1500);
lcd.setCursor(0,0);
lcd.print("O O O");
lcd.setCursor(0,1);
lcd.print("Loading /temp");
delay(1500);
lcd.setCursor(0,0);
lcd.clear();
lcd.print("O O O O O O");
lcd.setCursor(0,1);
lcd.print("Loading /txt");
delay(1500);
lcd.setCursor(0,0);
lcd.print("O O O O O O O O");
lcd.setCursor(0,1);
lcd.print("Loading /buttons");
delay(2500);
lcd.clear();
}
float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814);
}
void loop()
{
int button1State;
button1State = digitalRead(button1Pin);
int button2State;
button2State = digitalRead(button2Pin);
float voltage, degreesC, degreesF;
voltage = getVoltage(temperaturePin);
degreesC = (voltage - 0.5) * 100.0;
degreesF = degreesC * (9.0/5.0) + 32.0;
lcd.setCursor(0,0);
lcd.print("CrystalOS - v2.0");
lcd.setCursor(0,1);
lcd.print("Blue = Temp");
delay(1000);
if (button1State == LOW)
{
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Voltage ");
  lcd.setCursor(0,1);
  lcd.print(voltage);
  start;
  lcd.print("Celsius");
  lcd.setCursor(0,1);
  lcd.print(degreesC);
  start;
  lcd.print("Fahrenheit");
  lcd.setCursor(0,1);
  lcd.print(degreesF);
  delay(2000);
}
if (button2State == LOW)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CrystalOS - v2.0");
  lcd.setCursor(0,1);
  lcd.print("Made by Sammy");
  start;
  lcd.print("j.mp/crystalos");
  lcd.setCursor(0,1);
  lcd.print("Public on GitHub");
  start;
  lcd.print("Thanks for");
  lcd.setCursor(0,1);
  lcd.print("using");
  start;
  lcd.print("Updates:");
  lcd.setCursor(0,1);
  lcd.print("- Add updates");
  start;
  lcd.print("On GitHub");
  lcd.setCursor(0,1);
  lcd.print("- Updates to OS");
  start;
  lcd.print("- Shorten stuff");
  lcd.print("- Create OS");
}
}
