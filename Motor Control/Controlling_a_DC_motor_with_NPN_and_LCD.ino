/*
 Fading
 
 This example shows how to fade an LED using the analogWrite() function.
 
 The circuit:
 * LED attached from digital pin 9 to ground.
 
 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe
 
 http://arduino.cc/en/Tutorial/Fading
 
 This example code is in the public domain.
 
 */

int ledPin = 9;    // LED connected to digital pin 9
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display
int serialData = 0;
void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.print("Arduino up and running");
}

void loop()  { 
delay(1000);
  lcd.clear();
  lcd.print("Fan speeding up...");
  for(int fadeValue = 100 ; fadeValue <= 255; fadeValue +=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(300);
delay(10000);
  lcd.clear();
  lcd.print("Fan slowing down...");
  for(int fadeValue = 255 ; fadeValue >= 100; fadeValue -=1) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(300);                            
  }    
  } 
}


