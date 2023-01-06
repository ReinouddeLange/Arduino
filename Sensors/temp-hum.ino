#include <Wire.h>
#include <AM2321.h>
#include "U8glib.h"

char specialK;
String temp;
String hum;
float readByAM2321(int num) {
	AM2321 am2321;
	am2321.read();
	float sensor_tem=am2321.temperature/10.0;
	float sensor_hum=am2321.humidity/10.0;
	delay(500);
	if(num==1) {
		return sensor_tem;
	}
	else if(num==2) {
		return sensor_hum;
	} else {
		return 0.0;
	}
}

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
#define setFont_L u8g.setFont(u8g_font_fur20)
#define setFont_S u8g.setFont(u8g_font_fixed_v0r)
#define setFont_M u8g.setFont(u8g_font_9x18)

void setup()
{
  specialK = 176;
  temp = "";
  hum = "";
  Serial.begin(115200);
}

void loop()
{
  temp = String(readByAM2321(1)) + String(String(String(" ") + String(String("")+specialK)) + String("C"));
  hum = String(readByAM2321(2)) + String(" %");
  u8g.undoRotation();
  u8g.firstPage();
  do {
    setFont_L;
    u8g.setPrintPos(15, 20);
    u8g.print(temp);
    setFont_L;
    u8g.setPrintPos(15, 60);
    u8g.print(hum);
  } while( u8g.nextPage() );

  Serial.println(temp);
  Serial.println(hum);
  delay(500);

}
