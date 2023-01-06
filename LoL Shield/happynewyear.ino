
#include "Charliplexing.h"
#include "Myfont.h"

#include "Arduino.h"


  int leng1=0; //provides the length of the char array
  unsigned char line1[]="De feestdagen zijn voorbij, een nieuw jaar is gekomen. \0"; //text has to end with '\0' !!!!!!
  int leng2=0; //provides the length of the char array
  unsigned char line2[]="Wij wensen jullie God's zegen in het nieuwe jaar \0"; //text has to end with '\0' !!!!!!
  int leng3=0; //provides the length of the char array
  unsigned char line3[]="en een gelukkig 2014! \0"; //text has to end with '\0' !!!!!!
  int leng4=0; //provides the length of the char array
  unsigned char line4[]="The holidays are over, a new year has come. \0"; //text has to end with '\0' !!!!!!
  int leng5=0; //provides the length of the char array
  unsigned char line5[]="We wish you God's blessing in the new year \0"; //text has to end with '\0' !!!!!!
  int leng6=0; //provides the length of the char array
  unsigned char line6[]="and a happy 2014! \0"; //text has to end with '\0' !!!!!!
  int leng7=0; //provides the length of the char array
  unsigned char line7[]="Greetings from:  \0"; //text has to end with '\0' !!!!!!
  int leng8=0; //provides the length of the char array
  unsigned char line8[]="Eugenie, Reinoud, Esmee, Sander and Vincent!    \0"; //text has to end with '\0' !!!!!!


/* -----------------------------------------------------------------  */
/** MAIN program Setup
 */
void setup()                    // run once, when the sketch starts
{
  LedSign::Init();
    for(int i=0; ; i++){ //get the length of the text
    if(line1[i]==0){
      leng1=i;
      break;
    }
    
  }

  LedSign::Init();
    for(int i=0; ; i++){ //get the length of the text
    if(line2[i]==0){
      leng2=i;
      break;
    }
    
  }
  LedSign::Init();
    for(int i=0; ; i++){ //get the length of the text
    if(line3[i]==0){
      leng3=i;
      break;
    }
    
  }
  LedSign::Init();
    for(int i=0; ; i++){ //get the length of the text
    if(line4[i]==0){
      leng4=i;
      break;
    }
    
  }
  LedSign::Init();
    for(int i=0; ; i++){ //get the length of the text
    if(line5[i]==0){
      leng5=i;
      break;
    }
    
  }
  LedSign::Init();
    for(int i=0; ; i++){ //get the length of the text
    if(line6[i]==0){
      leng6=i;
      break;
    }
  }
  LedSign::Init();
    for(int i=0; ; i++){ //get the length of the text
    if(line7[i]==0){
      leng7=i;
      break;
    }   
  }
  LedSign::Init();
    for(int i=0; ; i++){ //get the length of the text
    if(line8[i]==0){
      leng8=i;
      break;
    }  
  }
}

/* -----------------------------------------------------------------  */
/** MAIN program Loop
 */

void loop()                     // run over and over again
{
//  Myfont::Banner(leng1,line1);
//  Myfont::Banner(leng2,line2);
//  Myfont::Banner(leng3,line3);
  Myfont::Banner(leng4,line4);
  Myfont::Banner(leng5,line5);
  Myfont::Banner(leng6,line6);
  Myfont::Banner(leng7,line7);
  Myfont::Banner(leng8,line8);
}
