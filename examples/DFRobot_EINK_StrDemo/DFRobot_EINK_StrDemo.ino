#include "Arduino.h"
#include "DFRobot_EINK.h"

/*****************Keywords instruction*****************/
//LUCENCY--->transparence
//WHITE----->black
//BLACK----->white
//RED------->red
/*****************Function instruction*****************/
//InkScreen_Error clear(uint8_t color)
  //*This function clears the screen
  //*color: BLACK or WHITE or RED
//disStr(uint8_t x, uint8_t y, char *ch, uint8_t color)
  //*This function is used to display Chinese and English strings
  //*(x,y):  coordinate (x∈(0,211),y∈(0,103)
  //*ch:     The string to display
  //*color:  BLACK or WHITE or RED
//disRefresh()
  //*This function is used to refresh the screen display
  
InkScreenBWR eink;

#define EINK_CS  2
#define EINK_DC  5
#define Font_CS  4

void setup(void){
  Serial.begin(115200);
  //Select the corresponding pins
  eink.begin(EINK_CS, Font_CS, EINK_DC);
  //Clear the screen and display white
  eink.clear(WHITE);
}

void loop(void){
	//Displays a string, red font
	eink.disStr(12,12,"这个Demo用来展示DFRobot_eink电子墨水屏显示中英文字符串。",RED);
	//Refresh screen display
	eink.disRefresh();
	delay(3000);
	//Clear the screen and display white
	eink.clear(WHITE);
	
	//Displays a string, red font
	eink.disStr(12,12,"This Demo is used to show the DFRobot_eink e-ink screen displaying Chinese and English strings.",RED);
	//Refresh screen display
	eink.disRefresh();
	delay(3000);
}


