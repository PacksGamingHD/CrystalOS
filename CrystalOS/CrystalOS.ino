/*
CrystalOS - Made by PacksGamingHD
*/
/** Code Guide
 * lcd.print(""); - Print a message to the LCD
 * delay() - What number you put there, it will delay the code *IMPORTANT - YOU MUST PUT THIS AFTER YOU FINISH THE SECOND LINE OR YOU WONT SEE IT*
 * lcd.clear(); - Clears the LCD
 * if (button1State == LOW) - When you push button 1 then it will do what you put in the code
 * lcd.setCursor(0,0); - Sets the cursor to the first line
 * lcd.setCursor(0,1); - Sets the cursor to the second line
 * start(); - Delays 2000, sets the cursor to the first line and clear the LCD
 * Find all of the commands here: http://arduino.cc/en/Reference/LiquidCrystal
*/
#include <LiquidCrystal.h> // Include the LiquidCrystal libraries 
LiquidCrystal lcd(12,11,5,4,3,2); // Define the pins
const int button1Pin = 7; // This is button 1
const int button2Pin = 8; // This is button 2
const int temperaturePin = 0; // This is the pin the tempature sensor uses
void start() // This delays two seconds, set the cursor to the first line and clears the LCD
{
  delay(2000);
  lcd.setCursor(0,0);
  lcd.clear();
}
void start1() // Same as above but it sets the cursor to the second line
{
  delay(2000);
  lcd.setCursor(0,1);
  lcd.clear();
}
void setup() // Setup code
{
pinMode(button1Pin, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
  Serial.begin(14400);
  lcd.setCursor(0,0);
  // Below is the code that displays when you plug it in or reset the Arduino
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
float getVoltage(int pin) // For the tempature sensor
{
  return (analogRead(pin) * 0.004882814);
}
void loop() // This is the main code
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
lcd.print("CrystalOS - v3.0");
lcd.setCursor(0,1);
lcd.print("Blue = Tempature");
if (button1State == LOW) // If button 1 is pressed then tell the tempature
{
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Voltage ");
  lcd.setCursor(0,1);
  lcd.print(voltage);
  start();
  lcd.print("Celsius");
  lcd.setCursor(0,1);
  lcd.print(degreesC);
  start();
  lcd.print("Fahrenheit");
  lcd.setCursor(0,1);
  lcd.print(degreesF);
  delay(2000);
}
if (button2State == LOW) // If button 2 is pressed then print info
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CrystalOS - v2.0");
  lcd.setCursor(0,1);
  lcd.print("Made by Sammy");
  start();
  lcd.print("j.mp/crystalos");
  lcd.setCursor(0,1);
  lcd.print("Public on GitHub");
  start();
  lcd.print("Thanks for using");
  start();
  lcd.print("Updates:");
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Change to 3.0");
  lcd.setCursor(0,1); 
  lcd.print("Add tempature");
  start();
  lcd.print("Clean code");
  lcd.setCursor(0,1);
  lcd.print("Added to Github");
  start();
  lcd.print("Updates to OS");
  lcd.setCursor(0,1);
  lcd.print("Created OS");
}
}
