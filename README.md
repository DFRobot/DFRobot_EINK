# EINK 

Provide an Arduino library to control the e-ink screen display, via SPI communication.

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)

* [History](#history)
* [Credits](#credits)
<snippet>
<content>

## Summary

Clear screen, change point, underline, draw rectangle, draw circle, Chinese and English character display

## Installation

To use the library to download the zip file, unzip it into a folder named DFRobot_EINK.Then put this folder into the Arduino\libraries directory.Finally run the inkScreenDemo.ino in the example folder.
	
## Methods

```C++	

#include <DFRobot_EINK.h>

//Select the corresponding pins
void begin(const char cs_W21, const char cs_GT30, const char dc);
   *cs_W21:   EINK Piece of selected pin
   *cs_GT30:  FONT Piece of selected pin
   *dc:       DC Control pin

//Clear the screen(BLACK or WHITE or RED)
InkScreen_Error clear(uint8_t color);

//Image display (212 * 104)
void picDisplay(const unsigned char *pic_bw, const unsigned char *pic_red);
   *pic_bw:   Black and white part
   *pic_red:  The red part
 
//The refresh screen
void disRefresh();

//Display Chinese and English strings
void disStr(uint8_t x, uint8_t y, char *ch, uint8_t color);
  *(x,y):  coordinate (x∈(0,211),y∈(0,103)
  *ch:     The string to display
  *color:  BLACK or WHITE or RED

//Create Point
InkScreen_Error drawPoint(const unsigned char x, const unsigned char y, const unsigned char color);
  *(x,y):  coordinate (x∈(0,211),y∈(0,103)
  *color:  BLACK or WHITE or RED

//Draw a straight line
InkScreen_Error drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t color);
  *[(x1,y1),(x2,y2)]:    The endpoint coordinates (x1/x2∈(0,211),y1/y2∈(0,103))
  *color:                BLACK or WHITE or RED

//Draw a rectangular
InkScreen_Error drawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t color);
  *(x1,x2):  The starting coordinate of the horizontal coordinate (x1/x2∈(0,211))
  *(y1,y2):  The starting coordinate of the vertical coordinate (y1/y2∈(0,103))
  *color:    BLACK or WHITE or RED

//Specify the center and radius to draw the circle
InkScreen_Error drawCircle(uint16_t xc, uint16_t yc, uint16_t r, uint16_t fill, uint8_t color);
  *(xc,yc):  Center coordinates (xc∈(0,211),yc∈(0,103)
  *r:        radii(r<=52)
  *fill:     0:Hollow   1:solid

//Rectangle filling
InkScreen_Error rectangleFILL(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t color);
  *(x1,x2):  The starting coordinate of the horizontal coordinate (x1∈(0,211),y1∈(0,103)
  *(y1,y2):  The starting coordinate of the vertical coordinate (x2∈(0,211),y2∈(0,103)
  *color:    BLACK or WHITE or RED

```

## History

- Sep 5, 2017 - Version 1.0.0 released.

## Credits

Written by DFRobot_xiaowo, 2017. (Welcome to our [website](https://www.dfrobot.com/))
