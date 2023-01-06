/*
 * Example for the SpeechChip library by Jacob Field. 
 * The ALD pin is connected to pin 8. The allophones DD1,
 * DD2, and SS have been renamed to D1, D2, and S for 
 * conflict reasons.
 */

#include <SpeechChip.h>

SpeechChip SpeechChip(8); //Tell the library that the Spo's ALD pin is connected to digital pin 8

void setup() {
  // Nothing here now!
}

void loop() {

  //Say "HELLO:
  SpeechChip.HH2();
  SpeechChip.EH();
  SpeechChip.LL();
  SpeechChip.OW();
  SpeechChip.PA5();

  SpeechChip.WW();
  SpeechChip.OR();
  SpeechChip.LL();
  SpeechChip.D1();
  SpeechChip.PA5();

  delay(1024);

  SpeechChip.DH2();
  SpeechChip.IH();
  SpeechChip.S();
  SpeechChip.PA5();
  SpeechChip.IH();
  SpeechChip.S();
  SpeechChip.PA5();
  SpeechChip.AA();
  SpeechChip.PA5();
  SpeechChip.RR1();
  SpeechChip.OW();
  SpeechChip.PA2();
  SpeechChip.BB2();
  SpeechChip.AA();
  SpeechChip.PA3();
  SpeechChip.TT2();
  SpeechChip.PA5();
  

  delay(1024);
}
