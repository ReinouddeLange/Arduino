/*
 Aangepast voor het weergeven van eigen afbeeldingen
*/

#include <avr/pgmspace.h>  //AVR library for writing to ROM
#include <Charliplexing.h> //Imports the library, which needs to be
                           //Initialized in setup.

int blinkdelay = 2000;      //Sets the time each frame is shown

/*
The BitMap array is what contains the frame data. Each line is one full frame.
Since each number is 16 bits, we can easily fit all 14 LEDs per row into it.
The number is calculated by adding up all the bits, starting with lowest on
the left of each row. 18000 was chosen as the kill number, so make sure that
is at the end of the matrix, or the program will continue to read into memory.

Here PROGMEM is called, which stores the array into ROM, which leaves us
with our RAM. You cannot change the array during run-time, only when you
upload to the Arduino. You will need to pull it out of ROM, which is covered
below. If you want it to stay in RAM, just delete PROGMEM
*/
uint16_t BitMap[][9] PROGMEM = {
//Display I
{1008,1008,192,192,192,192,192,1008,1008},
//Display heart
{3612,4386,4290,4098,2052,1032,528,288,192},
//Display Arduino logo
{0,3612,4386,9409,11997,9409,4386,3612,0},
{18000}
};

void setup() {
  LedSign::Init();  //Initializes the screen
}
void loop() {
  DisplayBitMap();  //Displays the bitmap
}

void DisplayBitMap()
{
  boolean run=true;    //While this is true, the screen updates
  byte frame = 0;      //Frame counter
  byte line = 0;       //Row counter
  unsigned long data;  //Temporary storage of the row data

  while(run == true) {
    for(line = 0; line < 9; line++) {

      //Here we fetch data from program memory with a pointer.
      data = pgm_read_word_near (&BitMap[frame][line]);
      
      //Kills the loop if the kill number is found
      if (data==18000){
        run=false;
      }
      
      //This is where the bit-shifting happens to pull out
      //each LED from a row. If the bit is 1, then the LED
      //is turned on, otherwise it is turned off.
      else for (byte led=0; led<14; ++led) {
        if (data & (1<<led)) {
          LedSign::Set(led, line, 1);
        }
        else {
          LedSign::Set(led, line, 0);
        }
      }

    }
    
    //Delays the next update
    delay(blinkdelay);        
    frame++;  
  }
}
