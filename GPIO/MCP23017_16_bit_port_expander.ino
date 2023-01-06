/*
** MCP23017 16 bit Port Expander
** Example code to flash LED on GPB0
** Created 06 Aug 2012
**
** This example code is in the public domain.
** www.hobbytronics.co.uk
*/

#include <Wire.h>

const byte  mcp_address=0x20;      // I2C Address of MCP23017 Chip
const byte  GPIOA=0x12;            // Register Address of Port A
const byte  GPIOB=0x13;            // Register Address of Port B

void setup()
{
  //Send settings to MCP device
  Wire.begin();              // join i2c bus (address optional for master)

  // IOCON.BANK defaults to 0 which is what we want.
  // So we are using Table 1-4 on page 9 of datasheet
  
  Wire.beginTransmission(mcp_address);
  Wire.write((byte)0x00); // IODIRA register
  Wire.write((byte)0x00); // set all of bank A to outputs
  Wire.write((byte)0x00); // set all of bank B to outputs 
  Wire.endTransmission();
  
}

void loop()
{
  Wire.beginTransmission(mcp_address);
  Wire.write(GPIOA);      // address bank A
  Wire.write((byte)0x1);  // value to send - pin A1 HIGH
  Wire.endTransmission();
  
  delay(500);

  Wire.beginTransmission(mcp_address);
  Wire.write(GPIOA);    // address bank A
  Wire.write((byte)0x2);  // value to send - piA2 HIGH
  Wire.endTransmission();
  
  delay(500);
}
