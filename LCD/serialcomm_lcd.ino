//DFRobot.com
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display
int serialData = 0;
void setup()
{
  Serial.begin(9600); 
  lcd.init();                      // initialize the lcd 
 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("Power up!");
}

void loop()
{

  if (Serial.available() > 0)
  {
    serialData = Serial.read();
    Serial.println(serialData);
    lcd.print(serialData);
  }  
}
