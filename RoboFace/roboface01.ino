#include "FastLED.h"

///////////////////////////////////////////////////////////////////////////////////////////
//
// Testing WS2812B LEDs on McRoboFace
// Shows various expressions
//    
///////////////////////////////////////////////////////////////////////////////////////////
 

// WS2812B definitions
#define NUM_LEDS 17
#define DATA_PIN A0
CRGB leds[NUM_LEDS];

int bright = 40;

// This function sets up the leds and tells the controller about them
void setup()
{
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(1000);

  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(bright);  // sets the maximum brightness level. All values are scalled to fit in this range
  allOff();
}

int wait = 800; // This is the delay in ms between LED colour changes
byte smileData[14]   = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
byte frownData[14]   = {1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0};
byte grimaceData[14] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1};
byte oooohData[14]   = {0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1};

// This function runs over and over, and is where you do the magic to light your leds.
void loop()
{
  allOff();
  nose(0, 0, 30);
  smile(30, 0, 0);
  delay(wait);
  eyes(0, 30, 0);
  frown(0, 255, 0);
  delay(wait);
  eyes(0, 0, 255);
  nose(0, 255, 0);
  grimace(0, 0, 255);
  delay(wait);
  ooooh(255, 255, 255);
  delay(wait);
}

void nose(int red, int green, int blue)
{
  leds[14] = CRGB (green, red, blue);
}

void eyes(int red, int green, int blue)
{
  leds[16] = leds[15] = CRGB (green, red, blue);
}

void smile(int red, int green, int blue)
{
  for(int i=0; i<14; i++)
  {
    leds[i] = 0;
    if (smileData[i] != 0)
      leds[i] = CRGB(green, red, blue);
  }
  FastLED.show();
}

void grimace(int red, int green, int blue)
{
  for(int i=0; i<14; i++)
  {
    leds[i] = 0;
    if (grimaceData[i] != 0)
      leds[i] = CRGB(green, red, blue);
  }
  FastLED.show();
}

void frown(int red, int green, int blue)
{
  for(int i=0; i<14; i++)
  {
    leds[i] = 0;
    if (frownData[i] != 0)
      leds[i] = CRGB(green, red, blue);
  }
  FastLED.show();
}

void ooooh(int red, int green, int blue)
{
  for(int i=0; i<14; i++)
  {
    leds[i] = 0;
    if (oooohData[i] != 0)
      leds[i] = CRGB(green, red, blue);
  }
  FastLED.show();
}

// Turns all the LEDs to OFF
void allOff()
{
  for (int i=0; i<NUM_LEDS; i++)
    leds[i] = 0;
  FastLED.show();
}

// Sets all the LEDs to the same colour
void setAll(int red, int green, int blue)
{
  for (int i=0; i<NUM_LEDS; i++)
  {
    leds[i].g = red;
    leds[i].r = green;
    leds[i].b = blue;
  }
  FastLED.show();
}


