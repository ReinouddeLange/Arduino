#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,16,2);  // set the LCD address to 0x20 for a 16 chars and 2 line display
String inputString = "";         // a string to hold incoming data
String displayString = "";       // string to display on lcd
boolean stringComplete = false;  // whether the string is complete
int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
    Serial.println("ready to receive!");
    lcd.print("Power On");
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    lcd.clear();
    lcd.print(displayString);
    if (displayString == "set led on") {
      digitalWrite(led, HIGH);
    }
    if (displayString == "set led off") {
      digitalWrite(led, LOW);
    }  
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}
/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
    else {
      displayString = inputString;
    }
    
  }
}
