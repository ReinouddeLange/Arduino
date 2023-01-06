//DFRobot.com

#include <Wire.h> 

#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x20,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display



void setup()

{

  lcd.init();                      // initialize the lcd 

 

  // Print a message to the LCD.

  lcd.backlight();

  lcd.print("Het Arduino - de");
  lcd.setCursor(0, 1);
  lcd.print("Lange Programma");

}



void loop()

{

}
