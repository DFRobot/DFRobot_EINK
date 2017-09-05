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
//picDisplay(const unsigned char *pic_bw, const unsigned char *pic_red)
  //*This function is used to draw points
  //*pic_bw:   Black and white part
  //*pic_red:  The red part
//disRefresh()
  //*This function is used to refresh the screen display

InkScreenBWR eink;

#define EINK_CS  2
#define EINK_DC  5
#define Font_CS  4

const unsigned char  DFRobot_bw[] =
{
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XE0,0X0F,0XFF,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XF0,0X1F,0XFF,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF8,0X3F,0XFF,
0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,
0X00,0X00,0X00,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,0X00,0X00,0X00,
0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,0X03,0XFF,0X80,0X00,0X1C,0X3F,
0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,0X0F,0XFF,0XF0,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,
0XFF,0XFF,0XF8,0X00,0X3F,0XFF,0XFC,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,
0X00,0X7F,0XFF,0XFE,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,0XFF,0XFF,
0XFE,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,0XFC,0X00,0X3F,0X00,0X1C,
0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,0XE0,0X00,0X07,0X00,0X1C,0X3F,0XFF,0XFF,
0XF7,0XFF,0XFF,0XF8,0X00,0XE0,0X00,0X07,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,
0XF8,0X00,0XE0,0X00,0X07,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,0XFC,
0X00,0X3F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,0X7F,0XFF,0XFF,0X00,
0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,0X7F,0XFF,0XFE,0X00,0X1C,0X3F,0XFF,
0XFF,0XF7,0XFF,0XFF,0XF8,0X00,0X3F,0XFF,0XFC,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,
0XFF,0XF8,0X00,0X0F,0XFF,0XF0,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,
0X01,0XFF,0XC0,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,0X0F,0XFF,0XF0,
0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0X39,0XF8,0X00,0X3F,0XFF,0XFC,0X00,0X1C,0X3F,
0XFF,0XFF,0XF7,0XFF,0X31,0XF8,0X00,0X7F,0XFF,0XFE,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,
0XFF,0XFF,0XF8,0X00,0XFF,0XFF,0XFE,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0X7F,0XF8,
0X00,0XFC,0X00,0X3F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFE,0X7F,0XF8,0X00,0XE0,0X00,
0X07,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFE,0X7F,0XF8,0X00,0XE0,0X00,0X07,0X00,0X1C,
0X3F,0XFF,0XFF,0XF7,0XFC,0X7F,0XF8,0X00,0XE0,0X00,0X07,0X00,0X1C,0X3F,0XFF,0XFF,
0XF7,0XF8,0X00,0XF8,0X00,0XFC,0X00,0X3F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XBB,0XFF,
0XF8,0X00,0X7F,0XFF,0XFF,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0X87,0XFF,0XF8,0X00,0X7F,
0XFF,0XFC,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XF3,0X07,0XF8,0X00,0X3F,0XFF,0XFC,0X00,
0X1C,0X3F,0XFF,0XFF,0XF7,0XFC,0XF3,0XF8,0X00,0X0F,0XFF,0XF0,0X00,0X1C,0X3F,0XFF,
0XFF,0XF7,0XFE,0X7B,0XF8,0X00,0X01,0XFF,0XDF,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XC7,
0X7F,0XF8,0X00,0X00,0X00,0X1F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XF1,0X01,0XF8,0X00,
0X00,0X00,0X1F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFE,0X7F,0XF8,0X00,0X00,0X00,0X1F,
0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0X3F,0XF8,0X00,0X00,0X00,0X1F,0X00,0X1C,0X3F,
0XFF,0XFF,0XF7,0XFF,0XDF,0XF8,0X00,0XE0,0X1F,0XC0,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,
0XFF,0XFF,0XF8,0X00,0XF8,0X7F,0XF0,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0X93,0XF8,
0X00,0XF8,0XFF,0XFC,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XEA,0X81,0XF8,0X00,0XF9,0XFF,
0XFE,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XAA,0X8C,0XF8,0X00,0XFB,0XFE,0X3E,0X00,0X1C,
0X3F,0XFF,0XFF,0XF7,0X80,0X0E,0XF8,0X00,0XFB,0XF8,0X1F,0X00,0X1C,0X3F,0XFF,0XFF,
0XF7,0XE5,0X46,0XF8,0X00,0XFF,0XF0,0X0F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XF5,0X56,
0XF8,0X00,0XFF,0XE0,0X0F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0X83,0XD0,0XF8,0X00,0XFF,
0XE0,0X1F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XE0,0X03,0XF8,0X00,0X7F,0XC0,0X1F,0X00,
0X1C,0X3F,0XFF,0XFF,0XF7,0XF3,0XFF,0XF8,0X00,0X1F,0XC0,0X1F,0X00,0X1C,0X3F,0XFF,
0XFF,0XF7,0XFC,0X7F,0XF8,0X00,0X07,0XC0,0X1F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFE,
0X7F,0XF8,0X00,0X01,0XC0,0X1E,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XBF,0XF8,0X00,
0XE0,0X1F,0XC0,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XF8,0X00,0XF8,0X3F,0XF0,
0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XEF,0XF8,0X00,0XF8,0XFF,0XFC,0X00,0X1C,0X3F,
0XFF,0XFF,0XF7,0XFD,0XEF,0XF8,0X00,0XF9,0XFF,0XFE,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,
0XF1,0XCF,0XF8,0X00,0XFB,0XFE,0X3E,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XED,0XCF,0XF8,
0X00,0XFB,0XF8,0X1F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XED,0XAF,0XF8,0X00,0XFF,0XF0,
0X0F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XA1,0X27,0XF8,0X00,0XFF,0XE0,0X0F,0X00,0X1C,
0X3F,0XFF,0XFF,0XF7,0XAF,0X40,0X78,0X00,0XFF,0XE0,0X1F,0X00,0X1C,0X3F,0XFF,0XFF,
0XF7,0X80,0XCD,0XF8,0X00,0X7F,0XC0,0X1F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XB7,0X17,
0XF8,0X00,0X1F,0XC0,0X1F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XB1,0XB7,0XF8,0X00,0X07,
0XC0,0X1F,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XF6,0XDF,0XF8,0X00,0X01,0XC0,0X1E,0X00,
0X1C,0X3F,0XFF,0XFF,0XF7,0XF9,0XE7,0XF8,0X00,0X00,0X00,0X00,0X00,0X1C,0X3F,0XFF,
0XFF,0XF7,0XFF,0XF7,0XF8,0X00,0X00,0X00,0X00,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,
0XF7,0XF8,0X00,0X00,0X00,0X00,0X00,0X1C,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X3F,
0XFF,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,
0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,
0XDF,0XFF,0XFF,0X7F,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,
0X7F,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XFF,
0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XEF,0XFC,0X3F,0XFF,
0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XEF,0XE7,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,
0XFF,0XDF,0XFF,0XFF,0X7F,0XEF,0XC7,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,
0XFF,0X7F,0XED,0XC7,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XE8,
0XCF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0X03,0X1F,0XFC,0X3F,
0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0X83,0X1F,0XFC,0X3F,0XFF,0XFF,0XF7,
0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XEB,0X5F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,
0XFF,0XFF,0X7F,0XEA,0X4F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,
0XE4,0XCF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XF5,0XEF,0XFC,
0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XA5,0XE7,0XFC,0X3F,0XFF,0XFF,
0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0X01,0XEF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,
0XDF,0XFF,0XFF,0X7F,0XE0,0X0F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,
0X7F,0XEE,0X07,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XE6,0XE7,
0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XF6,0XF7,0XFC,0X3F,0XFF,
0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFE,0XF7,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,
0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XF7,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,
0XFF,0X7F,0XFE,0XEF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFE,
0X7F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFE,0X7F,0XFC,0X3F,
0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0X9E,0X7F,0XFC,0X3F,0XFF,0XFF,0XF7,
0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0X00,0X7F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,
0XFF,0XFF,0X7F,0XF0,0X07,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,
0XEF,0X43,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XCF,0X7F,0XFC,
0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XCB,0X7F,0XFC,0X3F,0XFF,0XFF,
0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFB,0X7F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,
0XDF,0XFF,0XFF,0X7F,0XB3,0X7F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,
0X7F,0XB6,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0X84,0XFF,
0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0X80,0X7F,0XFC,0X3F,0XFF,
0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XD0,0X07,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,
0XFF,0XDF,0XFF,0XFF,0X7F,0XD4,0XC3,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,
0XFF,0X7F,0XD6,0X7F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XF7,
0X3F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XBF,0XFC,0X3F,
0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0X9F,0XFC,0X3F,0XFF,0XFF,0XF7,
0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XDF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,
0XFF,0XFF,0X7F,0XDF,0XBF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,
0XDF,0X9F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XD0,0XBF,0XFC,
0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0X90,0XBF,0XFC,0X3F,0XFF,0XFF,
0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XD2,0X3F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,
0XDF,0XFF,0XFF,0X7F,0X92,0X07,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,
0X7F,0X00,0XA3,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XD0,0XA3,
0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XD2,0X83,0XFC,0X3F,0XFF,
0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XD2,0X97,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,
0XFF,0XDF,0XFF,0XFF,0X7F,0XD0,0XB7,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,
0XFF,0X7F,0XEE,0X3F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XF7,
0XBF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XF7,0XBF,0XFC,0X3F,
0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0X81,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,
0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XC0,0X07,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,
0XFF,0XFF,0X7F,0XF7,0X07,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,
0XF7,0XF7,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XF7,0XFF,0XFC,
0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,
0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XE3,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,
0XDF,0XFF,0XFF,0X7F,0XE0,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,
0X7F,0XEF,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XAF,0X3F,
0XFC,0X3F,0XFB,0XFF,0XF7,0XFF,0XFB,0XDF,0XFF,0XFF,0X7F,0XAD,0X07,0XFC,0X3F,0XFB,
0XFF,0XF7,0X80,0X7B,0XDF,0XFF,0XFF,0X7F,0XA5,0X43,0XFC,0X3F,0XFB,0XFF,0XF7,0XFF,
0X7B,0XDF,0XFF,0XFF,0X7F,0XAD,0X53,0XFC,0X3F,0X9B,0X9F,0XF7,0XE1,0XDB,0XDF,0XFF,
0XFF,0X7F,0XAF,0X57,0XFC,0X3F,0XA3,0X63,0XF7,0XFB,0XCB,0XDF,0XFF,0XFF,0X7F,0X81,
0X57,0XFC,0X3F,0XB3,0X79,0XF7,0XDB,0X83,0XDF,0XFF,0XFF,0X7F,0XA1,0X07,0XFC,0X3F,
0XB4,0X7B,0XF7,0XC0,0X6B,0XDF,0XFF,0XFF,0X7F,0XAF,0X07,0XFC,0X3F,0XC3,0X7F,0XF7,
0XDB,0XEB,0XDF,0XFF,0XFF,0X7F,0XAD,0X57,0XFC,0X3F,0XFD,0XFF,0XF7,0XE0,0XFB,0XDF,
0XFF,0XFF,0X7F,0XA5,0X57,0XFC,0X3F,0XFD,0XFF,0XF7,0XFD,0X3B,0XDF,0XFD,0XFF,0X7F,
0XA5,0X57,0XFC,0X3F,0XFD,0XFF,0XF7,0XFD,0XDF,0XDF,0XFD,0XFF,0X7F,0XEC,0X03,0XFC,
0X3F,0XFD,0XFF,0XF7,0XFD,0XFF,0XDF,0XE5,0XFF,0X7F,0XEF,0X03,0XFC,0X3F,0XFF,0XFF,
0XF7,0XFF,0XFF,0XDF,0XAD,0XFF,0X7F,0XE3,0XFF,0XFC,0X3F,0XFF,0XFB,0XF7,0XFF,0XBD,
0XDF,0XD5,0XFF,0X7F,0XF8,0XFF,0XFC,0X3F,0X80,0X7B,0XF7,0XFF,0XBD,0XDE,0X25,0XFF,
0X7F,0XFF,0XFF,0XFC,0X3F,0XFF,0X7B,0XF7,0XF7,0XB9,0XDC,0XD0,0X07,0X7F,0XFF,0XEF,
0XFC,0X3F,0XE1,0XDB,0XF7,0XB6,0XBB,0XDE,0X45,0XFF,0X7F,0XDF,0X67,0XFC,0X3F,0XFB,
0XCB,0XF7,0XD5,0XB7,0XDE,0X92,0XFF,0X7F,0XDB,0X63,0XFC,0X3F,0XDB,0X83,0XF7,0XE5,
0XAF,0XDF,0XFE,0XFF,0X7F,0XDB,0X63,0XFC,0X3F,0XC0,0X6B,0XF7,0X00,0X1F,0XDF,0X96,
0XFF,0X7F,0XDB,0X63,0XFC,0X3F,0XDB,0XEB,0XF7,0XF9,0XA7,0XDF,0XFE,0XFF,0X7F,0X90,
0X67,0XFC,0X3F,0XE0,0XFB,0XF7,0XEA,0XDB,0XDF,0XFE,0XFF,0X7F,0X80,0X07,0XFC,0X3F,
0XFD,0X3B,0XF7,0XDB,0X5D,0XDF,0XFF,0XFF,0X7F,0XCA,0X4F,0XFC,0X3F,0XFD,0XDF,0XF7,
0XFF,0XDD,0XDF,0XFB,0XFF,0X7F,0XC2,0X4F,0XFC,0X3F,0XFD,0XFF,0XF7,0XFF,0XDF,0XDF,
0XEB,0XFF,0X7F,0XD0,0X4F,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0X0B,0XFF,0X7F,
0XD8,0X5F,0XFC,0X3F,0XFF,0XFF,0XF7,0XF7,0XFF,0XDD,0X60,0X0F,0X7F,0XFE,0X5F,0XFC,
0X3F,0XFF,0X3F,0XF7,0XE3,0XFF,0XDF,0X4D,0XFF,0X7F,0XD3,0X5F,0XFC,0X3F,0XFF,0X07,
0XF7,0XE8,0X3F,0XDF,0XEF,0XFF,0X7F,0XD2,0X5F,0XFC,0X3F,0XFF,0X77,0XF7,0XEF,0XBF,
0XDF,0X07,0XFF,0X7F,0X90,0X1F,0XFC,0X3F,0XCF,0X77,0XF7,0XEF,0XDF,0XDF,0XE8,0XFF,
0X7F,0XD2,0X9F,0XFC,0X3F,0XC3,0X43,0XF7,0XF7,0XDF,0XDF,0X77,0X7F,0X7F,0XF3,0X9F,
0XFC,0X3F,0XDD,0XBF,0XF7,0XF7,0XDF,0XDC,0X55,0XBF,0X7F,0XFB,0X9F,0XFC,0X3F,0XED,
0XFF,0XF7,0XF7,0XDF,0XDD,0XA0,0X7F,0X7F,0XFF,0X9F,0XFC,0X3F,0XEC,0X0F,0XF7,0XF0,
0X0F,0XDF,0X95,0X9F,0X7F,0XFF,0XDF,0XFC,0X3F,0XE3,0X37,0XF7,0XF3,0XFF,0XDF,0XFB,
0XFF,0X7F,0XFF,0XEF,0XFC,0X3F,0XFF,0XB7,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,
0XE7,0XFC,0X3F,0XFF,0XB3,0XF7,0XFF,0XBF,0XDF,0XFF,0XFF,0X7F,0XF7,0XC7,0XFC,0X3F,
0XFF,0X8F,0XF7,0XFF,0XBF,0XDF,0XF7,0XFF,0X7F,0XF7,0XC3,0XFC,0X3F,0XFF,0XFF,0XF7,
0XFF,0XBD,0XDF,0XE7,0XFF,0X7F,0XF7,0X87,0XFC,0X3F,0XFD,0XFF,0XF7,0XED,0XBB,0XDF,
0XE7,0XFF,0X7F,0XF7,0X0F,0XFC,0X3F,0XDD,0XFF,0XF7,0XA0,0X87,0XDF,0XCF,0XFF,0X7F,
0XF6,0X3F,0XFC,0X3F,0XDD,0XFF,0XF7,0XAE,0XB7,0XDF,0XB1,0XFF,0X7F,0X94,0X7F,0XFC,
0X3F,0XC1,0XFF,0XF7,0XF0,0X0B,0XDF,0X76,0X1F,0X7F,0X81,0XFF,0XFC,0X3F,0X2E,0XFF,
0XF7,0XF6,0XCD,0XDE,0XF7,0XCF,0X7F,0X80,0XFF,0XFC,0X3F,0X6A,0XFF,0XF7,0XFE,0XDD,
0XDD,0XFB,0XDF,0X7F,0XF0,0X7F,0XFC,0X3F,0XE6,0XFF,0XF7,0XF6,0XDF,0XDF,0X38,0XFF,
0X7F,0XF7,0X3F,0XFC,0X3F,0XEE,0XFF,0XF7,0X80,0X03,0XDF,0X9B,0X7F,0X7F,0XF7,0X9F,
0XFC,0X3F,0XEE,0X1F,0XF7,0XFB,0X7B,0XDF,0XEB,0XBF,0X7F,0XF3,0X8F,0XFC,0X3F,0XFF,
0XE3,0XF7,0XFB,0XBF,0XDF,0XF7,0XDF,0X7F,0XF3,0XCF,0XFC,0X3F,0XFF,0XF9,0XF7,0XFF,
0XDF,0XDF,0XFB,0XDF,0X7F,0XF3,0XC7,0XFC,0X3F,0XFF,0XFE,0XF7,0XFF,0XDF,0XDF,0XFF,
0XFF,0X7F,0XFF,0XE7,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,
0XE7,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XE7,0XFC,0X3F,
0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XEF,0XFC,0X3F,0XFF,0XFF,0XF7,
0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XFF,0XFC,0X3F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,
0XFF,0XFF,0X7F,0XFF,0XFF,0XFC,0X1F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,
0XFF,0XFF,0XF8,0X0F,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XFF,0XF0,
0X07,0XFF,0XFF,0XF7,0XFF,0XFF,0XDF,0XFF,0XFF,0X7F,0XFF,0XFF,0XE0,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,
};

const unsigned char  DFRobot_red[] =
{
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X20,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X21,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X33,0XF0,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0X00,0X00,0X00,0X00,0X13,0XF8,0X00,
0X00,0X00,0X00,0X00,0X07,0XFF,0XE0,0X00,0X00,0X00,0X1A,0X1C,0X00,0X00,0X00,0X00,
0X00,0X1F,0XFF,0XF8,0X00,0X00,0X00,0X0E,0X04,0X00,0X00,0X00,0X00,0X00,0X3C,0X00,
0X3C,0X00,0X00,0X00,0X07,0XFC,0X00,0X00,0X00,0X00,0X00,0X60,0X00,0X04,0X00,0X00,
0X00,0X03,0XFC,0X00,0X00,0X00,0X00,0X00,0X40,0X00,0X02,0X00,0X00,0X00,0X00,0XF8,
0X00,0X00,0X00,0X00,0X00,0X40,0X00,0X02,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X40,0X00,0X02,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X20,
0X00,0X06,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3C,0X00,0X3C,0X00,
0X00,0X00,0X38,0X04,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XF8,0X00,0X00,0X00,0X1F,
0XE4,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,0XE0,0X00,0X00,0X00,0X1F,0XFC,0X00,0X00,
0X00,0X00,0X00,0X00,0XFF,0X80,0X00,0X00,0X00,0X1F,0XFC,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X08,0X1C,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0X00,
0X00,0X00,0X00,0X00,0X04,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,0XE0,0X00,0X00,0X00,
0X00,0X04,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X3C,0X00,0X3C,0X00,0X00,0X00,0X20,0X20,0X00,0X00,0X00,0X00,
0X00,0X60,0X00,0X04,0X00,0X00,0X00,0X30,0X1C,0X00,0X00,0X00,0X00,0X00,0X40,0X00,
0X02,0X00,0X00,0X00,0X38,0X0C,0X00,0X00,0X00,0X00,0X00,0X40,0X00,0X02,0X00,0X00,
0X00,0X3C,0X04,0X00,0X00,0X00,0X00,0X00,0X40,0X00,0X02,0X00,0X00,0X00,0X2F,0X04,
0X00,0X00,0X00,0X00,0X00,0X20,0X00,0X06,0X00,0X00,0X00,0X27,0X84,0X00,0X00,0X00,
0X00,0X00,0X3C,0X00,0X3C,0X00,0X00,0X00,0X23,0XC4,0X00,0X00,0X00,0X00,0X00,0X1F,
0XFF,0XF8,0X00,0X00,0X00,0X21,0XE4,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,0XE0,0X00,
0X00,0X00,0X30,0X74,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0X80,0X00,0X00,0X00,0X3C,
0X3C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X04,0X1C,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X0E,0X00,0X00,0X00,0X00,0X0C,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X0E,0X00,0X00,0X00,0X00,0X04,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0E,
0X00,0X00,0X00,0X18,0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X3C,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XF8,0X00,
0X00,0X00,0X00,0X00,0X40,0X0F,0X80,0X00,0X00,0X00,0X3F,0XDC,0X00,0X00,0X00,0X00,
0X00,0X70,0X3F,0XE0,0X00,0X00,0X00,0X31,0X84,0X00,0X00,0X00,0X00,0X00,0X70,0X7C,
0X18,0X00,0X00,0X00,0X11,0X04,0X00,0X00,0X00,0X00,0X00,0X70,0XF0,0X0C,0X00,0X00,
0X00,0X08,0X0C,0X00,0X00,0X00,0X00,0X00,0X71,0XE0,0X04,0X00,0X00,0X00,0X00,0X1C,
0X00,0X00,0X00,0X00,0X00,0X71,0XC0,0X06,0X00,0X00,0X00,0X00,0X08,0X00,0X00,0X00,
0X00,0X00,0X73,0XC0,0X06,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X33,
0X80,0X06,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0X80,0X0E,0X00,
0X00,0X00,0X38,0X04,0X00,0X00,0X00,0X00,0X00,0X03,0X80,0X0E,0X00,0X00,0X00,0X1F,
0XE4,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0X0C,0X00,0X00,0X00,0X1F,0XFC,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFC,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X08,0X1C,0X00,0X00,0X00,0X00,0X00,0X40,0X0F,0X80,
0X00,0X00,0X00,0X00,0X04,0X00,0X00,0X00,0X00,0X00,0X70,0X3F,0XE0,0X00,0X00,0X00,
0X00,0X04,0X00,0X00,0X00,0X00,0X00,0X70,0X7C,0X18,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X70,0XF0,0X0C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X71,0XE0,0X04,0X00,0X00,0X00,0X08,0X00,0X00,0X00,0X00,0X00,0X00,0X71,0XC0,
0X06,0X00,0X00,0X00,0X1E,0X18,0X00,0X00,0X00,0X00,0X00,0X73,0XC0,0X06,0X00,0X00,
0X00,0X3F,0X0C,0X00,0X00,0X00,0X00,0X00,0X33,0X80,0X06,0X00,0X00,0X00,0X3F,0X8C,
0X00,0X00,0X00,0X00,0X00,0X0F,0X80,0X0E,0X00,0X00,0X00,0X30,0XCC,0X00,0X00,0X00,
0X00,0X00,0X03,0X80,0X0E,0X00,0X00,0X00,0X30,0X6C,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X0C,0X00,0X00,0X00,0X18,0X2C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X08,0X1C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X0C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X04,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XC0,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X27,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X20,0X1C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3C,0X04,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFC,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X23,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X20,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X30,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X2C,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XC0,0X00,0X00,0X00,0X01,0XF0,0XC0,0X00,0X00,0X00,
0X00,0X00,0X00,0X20,0X00,0X00,0X00,0X01,0XFF,0XC0,0X00,0X00,0X00,0X00,0X00,0X21,
0XF8,0X00,0X00,0X00,0X00,0X7F,0XF8,0X00,0X00,0X00,0X00,0X00,0X3F,0XFC,0X00,0X00,
0X00,0X00,0X2F,0XF8,0X00,0X00,0X00,0X00,0X00,0X3F,0XE0,0X00,0X00,0X00,0X00,0X10,
0XF8,0X00,0X00,0X00,0X00,0X00,0X3C,0X00,0X00,0X00,0X00,0X00,0X0C,0XC0,0X00,0X00,
0X00,0X00,0X00,0X33,0X00,0X00,0X00,0X00,0X00,0X02,0XC0,0X00,0X00,0X00,0X00,0X00,
0X20,0XC0,0X00,0X00,0X00,0X00,0X01,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X20,0X00,
0X00,0X00,0X00,0X00,0X40,0X00,0X00,0X00,0X00,0X00,0X20,0XF8,0X00,0X00,0X00,0X00,
0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X2F,0XFC,0X00,0X00,0X00,0X01,0XFF,0XE0,0X00,
0X00,0X00,0X00,0X00,0X3F,0XF0,0X00,0X00,0X00,0X01,0X1F,0XF0,0X00,0X00,0X00,0X00,
0X00,0X3F,0X00,0X00,0X40,0X00,0X01,0X00,0X38,0X00,0X00,0X00,0X00,0X00,0X30,0X00,
0X00,0X40,0X00,0X01,0XE0,0X08,0X00,0X00,0X00,0X00,0X00,0X20,0X00,0X00,0X7C,0X02,
0X00,0XFF,0XC8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XF2,0X00,0X3F,0XF8,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFE,0X00,0X0F,0XE0,0X00,0X00,0X00,
0X00,0X00,0X38,0X20,0X00,0X43,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X30,
0X1C,0X00,0X40,0X0E,0X01,0XF0,0X08,0X00,0X00,0X00,0X00,0X00,0X20,0X0C,0X00,0X00,
0X02,0X00,0XFF,0XC8,0X00,0X00,0X00,0X00,0X00,0X24,0X04,0X00,0X18,0X02,0X00,0XFF,
0XF8,0X00,0X00,0X00,0X00,0X00,0X27,0XC4,0X00,0X3E,0X00,0X00,0XCF,0XF8,0X00,0X00,
0X00,0X00,0X00,0X21,0X04,0X00,0X7F,0X00,0X00,0X40,0X38,0X00,0X00,0X00,0X00,0X00,
0X39,0X04,0X00,0X67,0X80,0X00,0X00,0X08,0X00,0X00,0X00,0X00,0X00,0X3F,0XE4,0X00,
0X41,0X80,0X00,0X00,0X08,0X00,0X00,0X00,0X00,0X00,0X3F,0XFC,0X00,0X40,0X80,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X23,0XFC,0X00,0X7C,0X82,0X00,0X40,0X00,0X00,
0X00,0X00,0X00,0X00,0X20,0X1C,0X00,0X7F,0XF2,0X00,0X20,0X40,0X00,0X00,0X00,0X00,
0X00,0X00,0X04,0X00,0X7F,0XFE,0X00,0X10,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X04,
0X00,0X43,0XFE,0X00,0X09,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XC0,0X00,0X40,0X0E,
0X00,0X06,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XE0,0X00,0X00,0X02,0X00,0X0A,0X00,
0X00,0X00,0X00,0X00,0X00,0X1F,0XF0,0X00,0X00,0X02,0X00,0X31,0X00,0X00,0X00,0X00,
0X00,0X00,0X30,0X38,0X00,0X7C,0X30,0X00,0X40,0X80,0X00,0X00,0X00,0X00,0X00,0X20,
0X08,0X00,0X3C,0X78,0X00,0X00,0X40,0X00,0X00,0X00,0X00,0X00,0X20,0X0C,0X00,0X40,
0XFC,0X00,0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X20,0X04,0X00,0X41,0XFE,0X00,0XF8,
0X70,0X00,0X00,0X00,0X00,0X00,0X38,0X04,0X00,0X43,0XC2,0X01,0XFC,0X38,0X00,0X00,
0X00,0X00,0X00,0X3F,0XE4,0X00,0X7F,0X82,0X01,0XCE,0X38,0X00,0X00,0X00,0X00,0X00,
0X3F,0XFC,0X00,0X3F,0X02,0X01,0X81,0X38,0X00,0X00,0X00,0X00,0X00,0X23,0XFC,0X00,
0X1E,0X04,0X00,0X80,0XB8,0X00,0X00,0X00,0X00,0X00,0X20,0X1C,0X00,0X00,0X3C,0X00,
0XC0,0X78,0X00,0X00,0X00,0X00,0X00,0X00,0X04,0X00,0X00,0X0E,0X00,0X60,0X78,0X00,
0X00,0X00,0X00,0X00,0X00,0X44,0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X00,0X00,0X00,
0X00,0X38,0X40,0X00,0X00,0X00,0X00,0X00,0X08,0X00,0X00,0X00,0X00,0X00,0X1C,0X60,
0X00,0X00,0X00,0X01,0XF0,0X08,0X00,0X00,0X00,0X00,0X00,0X10,0X78,0X00,0X00,0X00,
0X00,0XFF,0XC8,0X00,0X00,0X00,0X00,0X00,0X20,0X78,0X00,0X00,0X00,0X00,0XFF,0XF8,
0X00,0X00,0X00,0X00,0X00,0X20,0X5C,0X00,0X00,0X00,0X00,0XCF,0XF8,0X00,0X00,0X00,
0X00,0X00,0X20,0X44,0X00,0X00,0X00,0X00,0X40,0X38,0X00,0X00,0X00,0X00,0X00,0X20,
0X04,0X00,0X00,0X00,0X00,0X00,0X08,0X00,0X00,0X00,0X00,0X00,0X30,0X04,0X00,0X00,
0X00,0X00,0X00,0X08,0X00,0X00,0X00,0X00,0X00,0X18,0X04,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X1C,0X0C,0X00,0X00,0X00,0X00,0X60,0X00,0X00,0X00,
0X00,0X00,0X00,0X0F,0XF8,0X00,0X00,0X00,0X00,0XF8,0X70,0X00,0X00,0X00,0X00,0X00,
0X07,0XF8,0X00,0X00,0X00,0X01,0XFC,0X38,0X00,0X00,0X00,0X00,0X00,0X01,0XE0,0X00,
0X00,0X00,0X01,0XCE,0X38,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,
0X81,0X38,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0XB8,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XC0,0X78,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X60,0X78,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X18,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X08,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,
};

void setup(void){
  Serial.begin(115200);
  //Select the corresponding pins
  eink.begin(EINK_CS, Font_CS, EINK_DC);
  //Clear the screen and display white
  eink.clear(WHITE);
}

void loop(void){
	//Show a picture
	eink.picDisplay(DFRobot_bw, DFRobot_red);
	//Refresh screen display
    eink.disRefresh();
	delay(3000);
	
	//Clear the screen and display white
    eink.clear(WHITE);
}

