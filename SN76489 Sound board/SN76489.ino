//---------------------------------------
//SN76489 Digital Complex Sound Generator
//---------------------------------------
#define D0 2
#define D1 3
#define D2 4
#define D3 5
#define D4 6
#define D5 7
#define D6 8
#define D7 9
#define WE 10
//==============================================================
void setup()
{
  pinMode(D0, OUTPUT); pinMode(D1, OUTPUT); pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT); pinMode(D4, OUTPUT); pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT); pinMode(D7, OUTPUT);
  pinMode(WE, OUTPUT); digitalWrite(WE, HIGH);
  //------------------------------------------------------------
  SilenceAllChannels(); //mute all channels of SN76489
  delay(2000);
}
//==============================================================
void loop()
{ 
  SendByte(0x90); //channel 0 maximum volume
  //different tone frequencies @ channel 0
  SendByte(0x8F); SendByte(0x3F); //122Hz tone
  //delay(2000);
  //--------------------------------------------------------
  //SendByte(0x81); SendByte(0x27); //200Hz tone - strange tone
  //delay(2000);
  //--------------------------------------------------------
  //SendByte(0x81); SendByte(0x1A); //300Hz tone
  //delay(2000);
  //--------------------------------------------------------
  SendByte(0x8A); SendByte(0x0F); //500Hz tone
  delay(2000);
  //--------------------------------------------------------
  //for(byte vol=0x91; vol<=0x9F; vol++) //attenuate gradually
  //{
  //  SendByte(vol); delay(50);
  //}
  //SilenceAllChannels(); //mute all channels of SN76489
  //delay(2000); 
}
//==============================================================
void PutByte(byte b)
{
  digitalWrite(D0, (b&1)?HIGH:LOW);
  digitalWrite(D1, (b&2)?HIGH:LOW);
  digitalWrite(D2, (b&4)?HIGH:LOW);
  digitalWrite(D3, (b&8)?HIGH:LOW);
  digitalWrite(D4, (b&16)?HIGH:LOW);
  digitalWrite(D5, (b&32)?HIGH:LOW);
  digitalWrite(D6, (b&64)?HIGH:LOW);
  digitalWrite(D7, (b&128)?HIGH:LOW);
}
//==============================================================
void SendByte(byte b)
{
  digitalWrite(WE, HIGH);
  PutByte(b);
  digitalWrite(WE, LOW);
  delay(1);
  digitalWrite(WE, HIGH);
}
//==============================================================
void SilenceAllChannels()
{
  SendByte(0x9F); //mute channel 0
  SendByte(0xBF); //mute channel 1
  SendByte(0xDF); //mute channel 2
  SendByte(0xFF); //mute noise channel
}
