#include <Wire.h>
#include <AM2321.h>
#include "U8glib.h"

float temp_reading;
float hum_reading;
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
  temp_reading = 0.0;
  hum_reading = 0.0;
  specialK = 176;
  temp = "";
  hum = "";
  Serial.begin(115200);
}

void loop()
{
  temp_reading = readByAM2321(1);
  hum_reading = readByAM2321(2);
  temp = String(temp_reading, 1);
  hum = String(hum_reading,1);
  temp = String(temp) + String(String(String(" ") + String(String("")+specialK)) + String("C"));
  hum = String(hum) + String(" %");

  int(0);

  u8g.undoRotation();
  u8g.firstPage();
  do {
    setFont_L;
    u8g.setPrintPos(20, 20);
    u8g.print(temp);
    setFont_L;
    u8g.setPrintPos(20, 60);
    u8g.print(hum);
  } while( u8g.nextPage() );

  Serial.println(temp_reading, 1);
  Serial.println(hum_reading, 1);
  delay(500);

}
