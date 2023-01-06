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


int ledPin = 11;    // LED connected to digital pin 11
int ledPin2 = 10;    // LED connected to digital pin 10

void setup()  { 
  // nothing happens in setup 
} 

void loop()  { 
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    analogWrite(ledPin2, 255-fadeValue);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(100);                            
  } 

  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, 255-fadeValue);
    analogWrite(ledPin2, fadeValue);    
    // wait for 30 milliseconds to see the dimming effect    
    delay(100);                            
  }  

}


