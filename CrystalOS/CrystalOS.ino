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
#include <LiquidCrystal.h> // Include the LiquidCrystal library 
LiquidCrystal lcd(12,11,5,4,3,2); // Define the pins
const int button1Pin = 7; // This is button 1
const int button2Pin = 8; // This is button 2
const int temperaturePin = 0; // This is the pin the tempature sensor uses
void start() // This delays two seconds, set the cursor to the first line and clears the LCD
{
  delay(2000); // Delay 2000
  lcd.setCursor(0,0); // Set cursor to first line
  lcd.clear(); // Clear LCD
}
void start1() // Same as above but it sets the cursor to the second line
{
  delay(2000); // Delay 2000
  lcd.setCursor(0,1); // Set cursor to second line
  lcd.clear(); // Clear LCD
}
void boot1() // Delay 1500 then set LCD to first line
{
  delay(1500); // Delay 1500
  lcd.setCursor(0,0); // Set cursor to first line
}
void line1(); // Define line1
{
  lcd.setCursor(0,0); // Set the cursor to first line
}
void line2() // Define line2
{
  lcd.setCursor(0,1); // Set the cursor to the second line
}
void setup() // Setup code
{
pinMode(button1Pin, INPUT); // Button 1
pinMode(button2Pin, INPUT); // Button 2
  lcd.begin(16, 2); // 16 charachters on 2 lines
  lcd.clear(); // Clear LCD
  lcd.setCursor(0,0); // Set cursor to first line
  // Below is the code that displays when you plug it in or reset the Arduino
lcd.print("O"); // Print to LCD
lcd.setCursor(0,1); // Set cursor to second line
lcd.print("Starting up"); // Print to LCD
boot1(); // Run function boot1
lcd.print("O O"); // Print to LCD
line2(); // Set cursor to second line
lcd.print("Loading /home"); // Print to LCD
boot1(); // Run function boot1
lcd.print("O O O"); // Print to LCD
line2();// Run function line2
lcd.print("Loading /temp"); // Print to LCD
boot1(); // Run function boot1
lcd.clear(); // Clear LCD
lcd.print("O O O O O O"); // Print to LCD
line2(); // Run function line2
lcd.print("Loading /txt"); // Print to LCD
boot1(); // Run function boot1
lcd.print("O O O O O O O O"); // Print to LCD
lien2(); // Run function line2
lcd.print("Loading /buttons"); // Print to LCD
delay(2500); // Delay 2500
lcd.clear(); // Clear LCD
}
float getVoltage(int pin) // For the tempature sensor
{
  return (analogRead(pin) * 0.004882814); // Analog read pin
}
void loop() // This is the main code
{
int button1State; // Define button 1
button1State = digitalRead(button1Pin); // Tell where button 1 is 
int button2State; // Define button 2
button2State = digitalRead(button2Pin); // Tell where button 2 is
float voltage, degreesC, degreesF; // Define voltage, degreesC and degreesF
voltage = getVoltage(temperaturePin); // Tells what voltage is
degreesC = (voltage - 0.5) * 100.0; // Tells what the tempature can be
degreesF = degreesC * (9.0/5.0) + 32.0; // Convert tempature
line1(); // Run function line1
lcd.print("CrystalOS - v3.0"); // Print to LCD
line2(); // Run function line2
lcd.print("Blue = Tempature"); // Print to LCD
if (button1State == LOW) // If button 1 is pressed then tell the tempature
{
  line1(); // Run function line1
  lcd.clear(); // Clear LCD
  lcd.print("Voltage "); // Print to LCD
  line2(); // Run function line2
  lcd.print(voltage); // Print voltage to LCD
  start(); // Run function start
  lcd.print("Celsius"); // Print to LCD
  line2(); // Run function line2
  lcd.print(degreesC); // Print degreesC to LCD
  start(); // Run function start
  lcd.print("Fahrenheit"); // Print to LCD
  lcd.setCursor(0,1); // Set cursor to second line
  lcd.print(degreesF); // Print degreesF to LCD
  delay(2000); // Delay 2000
}
if (button2State == LOW) // If button 2 is pressed then print info
{
  lcd.clear(); // Clear LCD
  lcd.setCursor(0,0); // Set cursor to first line
  lcd.print("CrystalOS - v3.0"); // Print to LCD
  lcd.setCursor(0,1); // Set cursor to second line
  lcd.print("Made by Sammy"); // Print to LCD
  start(); // Run function start
  lcd.print("j.mp/crystalos"); // Print to LCD
  lcd.setCursor(0,1); // Set cursor to second line
  lcd.print("Public on GitHub"); // Print to LCD
  start(); // Run function start
  lcd.print("Thanks for using"); // Print to LCD
  start(); // Run function start
  lcd.print("Updates:"); // Print to LCD
  lcd.setCursor(0,0); // Set cursor to first line
  lcd.clear(); // Clear LCD
  lcd.print("Change to 3.0"); // Print to LCD
  lcd.setCursor(0,1); // Set cursor to second line
  lcd.print("Add tempature"); // Print to LCD
  start(); // Run function start
  lcd.print("Clean code"); // Print to LCD
  lcd.setCursor(0,1); // Set cursor to second line
  lcd.print("Added to Github"); // Print to LCD
  start(); // Run function start
  lcd.print("Updates to OS"); // Print to LCD
  lcd.setCursor(0,1); // Set cursor to second line
  lcd.print("Created OS"); // Print to LCD
}
}
