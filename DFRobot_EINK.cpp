#include"DFRobot_EINK.h"

eInk_dev eInkdev;
unsigned char  *DF_Display_bw = new unsigned char[2756];
unsigned char  *DF_Display_red = new unsigned char[2756];
const unsigned short ucs_gb2312_table[][2] = {
{0x00A4,0xA1E8}, {0x00A7,0xA1EC}, {0x00A8,0xA1A7}, {0x00B0,0xA1E3}, /****A1*****/
{0x00B1,0xA1C0}, {0x00B7,0xA1A4}, {0x00D7,0xA1C1}, {0x00F7,0xA1C2},
{0x02C7,0xA1A6}, {0x02C9,0xA1A5}, {0x2014,0xA1AA}, {0x2016,0xA1AC},  
{0x2018,0xA1AE}, {0x2019,0xA1AF}, {0x201C,0xA1B0}, {0x201D,0xA1B1},  
{0x2026,0xA1AD}, {0x2030,0xA1EB}, {0x2032,0xA1E4}, {0x2033,0xA1E5},  
{0x203B,0xA1F9}, {0x2103,0xA1E6}, {0x2116,0xA1ED}, {0x2190,0xA1FB},  
{0x2191,0xA1FC}, {0x2192,0xA1FA}, {0x2193,0xA1FD}, {0x2208,0xA1CA},  
{0x220F,0xA1C7}, {0x2211,0xA1C6}, {0x221A,0xA1CC}, {0x221D,0xA1D8},  
{0x221E,0xA1DE}, {0x2220,0xA1CF}, {0x2225,0xA1CE}, {0x2227,0xA1C4},  
{0x2228,0xA1C5}, {0x2229,0xA1C9}, {0x222A,0xA1C8}, {0x222B,0xA1D2},  
{0x222E,0xA1D3}, {0x2234,0xA1E0}, {0x2235,0xA1DF}, {0x2236,0xA1C3},  
{0x2237,0xA1CB}, {0x223D,0xA1D7}, {0x2248,0xA1D6}, {0x224C,0xA1D5},  
{0x2260,0xA1D9}, {0x2261,0xA1D4}, {0x2264,0xA1DC}, {0x2265,0xA1DD},  
{0x226E,0xA1DA}, {0x226F,0xA1DB}, {0x2299,0xA1D1}, {0x22A5,0xA1CD},  
{0x2312,0xA1D0}, {0x25A0,0xA1F6}, {0x25A1,0xA1F5}, {0x25B2,0xA1F8}, 
{0x25C7,0xA1F3}, {0x25CB,0xA1F0}, {0x25CE,0xA1F2}, {0x25CF,0xA1F1},  
{0x2605,0xA1EF}, {0x2606,0xA1EE}, {0x2640,0xA1E2}, {0x2642,0xA1E1},  
{0x3000,0xA1A1}, {0x3001,0xA1A2}, {0x3002,0xA1A3}, {0x3003,0xA1A8},  
{0x3005,0xA1A9}, {0x3008,0xA1B4}, {0x3009,0xA1B5}, {0x300A,0xA1B6},  
{0x300B,0xA1B7}, {0x300C,0xA1B8}, {0x300D,0xA1B9}, {0x300E,0xA1BA},  
{0x300F,0xA1BB}, {0x3010,0xA1BE}, {0x3011,0xA1BF}, {0x3013,0xA1FE},  
{0x3014,0xA1B2}, {0x3015,0xA1B3}, {0x3016,0xA1BC}, {0x3017,0xA1BD},
{0x25B3,0xA1F7}, {0x25C6,0xA1F4}, {0xFF04,0xA1E7}, {0xFF5E,0xA1AB}, 
{0xFFE0,0xA1E9}, {0xFFE1,0xA1EA},
{0x2161,0xA2F2}, {0x2162,0xA2F3}, {0x2163,0xA2F4}, {0x2164,0xA2F5}, /****A2*****/ 
{0x2165,0xA2F6}, {0x2166,0xA2F7}, {0x2167,0xA2F8}, {0x2168,0xA2F9},  
{0x2169,0xA2FA}, {0x216A,0xA2FB}, {0x216B,0xA2FC}, {0x2460,0xA2D9}, 
{0x2463,0xA2DC}, {0x2464,0xA2DD}, {0x2465,0xA2DE}, {0x2466,0xA2DF},  
{0x2467,0xA2E0}, {0x2468,0xA2E1}, {0x2469,0xA2E2}, {0x2474,0xA2C5},  
{0x2475,0xA2C6}, {0x2476,0xA2C7}, {0x2477,0xA2C8}, {0x2478,0xA2C9},  
{0x2479,0xA2CA}, {0x247A,0xA2CB}, {0x247B,0xA2CC}, {0x247C,0xA2CD},  
{0x247D,0xA2CE}, {0x247E,0xA2CF}, {0x247F,0xA2D0}, {0x2480,0xA2D1},  
{0x2481,0xA2D2}, {0x2482,0xA2D3}, {0x2483,0xA2D4}, {0x2484,0xA2D5},  
{0x2485,0xA2D6}, {0x2486,0xA2D7}, {0x2487,0xA2D8}, {0x2488,0xA2B1},  
{0x2489,0xA2B2}, {0x248A,0xA2B3}, {0x248B,0xA2B4}, {0x248C,0xA2B5},  
{0x248D,0xA2B6}, {0x248E,0xA2B7}, {0x248F,0xA2B8}, {0x2490,0xA2B9},  
{0x2491,0xA2BA}, {0x2492,0xA2BB}, {0x2493,0xA2BC}, {0x2494,0xA2BD},  
{0x2495,0xA2BE}, {0x2496,0xA2BF}, {0x2497,0xA2C0}, {0x2498,0xA2C1},  
{0x2499,0xA2C2}, {0x249A,0xA2C3}, {0x249B,0xA2C4}, {0x2461,0xA2DA}, 
{0x2462,0xA2DB}, {0x3220,0xA2E5}, {0x3221,0xA2E6}, {0x3229,0xA2EE},
{0x3222,0xA2E7}, {0x3223,0xA2E8}, {0x3224,0xA2E9}, {0x3225,0xA2EA},  
{0x3226,0xA2EB}, {0x3227,0xA2EC}, {0x3228,0xA2ED}, {0x2160,0xA2F1},
{0xFF01,0xA3A1}, {0xFF02,0xA3A2}, {0xFF03,0xA3A3}, {0xFF05,0xA3A5},  /****A3*****/
{0xFF06,0xA3A6}, {0xFF07,0xA3A7}, {0xFF08,0xA3A8}, {0xFF09,0xA3A9},  
{0xFF0A,0xA3AA}, {0xFF0B,0xA3AB}, {0xFF0C,0xA3AC}, {0xFF0D,0xA3AD},  
{0xFF0E,0xA3AE}, {0xFF0F,0xA3AF}, {0xFF10,0xA3B0}, {0xFF11,0xA3B1},  
{0xFF12,0xA3B2}, {0xFF13,0xA3B3}, {0xFF14,0xA3B4}, {0xFF15,0xA3B5},  
{0xFF16,0xA3B6}, {0xFF17,0xA3B7}, {0xFF18,0xA3B8}, {0xFF19,0xA3B9},  
{0xFF1A,0xA3BA}, {0xFF1B,0xA3BB}, {0xFF1C,0xA3BC}, {0xFF1D,0xA3BD},  
{0xFF1E,0xA3BE}, {0xFF1F,0xA3BF}, {0xFF20,0xA3C0}, {0xFF21,0xA3C1},  
{0xFF22,0xA3C2}, {0xFF23,0xA3C3}, {0xFF24,0xA3C4}, {0xFF25,0xA3C5},  
{0xFF26,0xA3C6}, {0xFF27,0xA3C7}, {0xFF28,0xA3C8}, {0xFF29,0xA3C9},  
{0xFF2A,0xA3CA}, {0xFF2B,0xA3CB}, {0xFF2C,0xA3CC}, {0xFF2D,0xA3CD},  
{0xFF2E,0xA3CE}, {0xFF2F,0xA3CF}, {0xFF30,0xA3D0}, {0xFF31,0xA3D1},  
{0xFF32,0xA3D2}, {0xFF33,0xA3D3}, {0xFF34,0xA3D4}, {0xFF35,0xA3D5},  
{0xFF36,0xA3D6}, {0xFF37,0xA3D7}, {0xFF38,0xA3D8}, {0xFF39,0xA3D9},  
{0xFF3A,0xA3DA}, {0xFF3B,0xA3DB}, {0xFF3C,0xA3DC}, {0xFF3D,0xA3DD},  
{0xFF3E,0xA3DE}, {0xFF3F,0xA3DF}, {0xFF40,0xA3E0}, {0xFF41,0xA3E1},  
{0xFF42,0xA3E2}, {0xFF43,0xA3E3}, {0xFF44,0xA3E4}, {0xFF45,0xA3E5},  
{0xFF46,0xA3E6}, {0xFF47,0xA3E7}, {0xFF48,0xA3E8}, {0xFF49,0xA3E9},  
{0xFF4A,0xA3EA}, {0xFF4B,0xA3EB}, {0xFF4C,0xA3EC}, {0xFF4D,0xA3ED},  
{0xFF4E,0xA3EE}, {0xFF4F,0xA3EF}, {0xFF50,0xA3F0}, {0xFF51,0xA3F1},  
{0xFF52,0xA3F2}, {0xFF53,0xA3F3}, {0xFF54,0xA3F4}, {0xFF55,0xA3F5},  
{0xFF56,0xA3F6}, {0xFF57,0xA3F7}, {0xFF58,0xA3F8}, {0xFF59,0xA3F9},  
{0xFF5A,0xA3FA}, {0xFF5B,0xA3FB}, {0xFF5C,0xA3FC}, {0xFF5D,0xA3FD},
{0xFFE3,0xA3FE}, {0xFFE5,0xA3A4},
};

DFRobot_EINKBWR::DFRobot_EINKBWR():
    DFR_W21_CS(2), DFR_W21_DC(12), DFR_GT30_CS(4)
{}

DFRobot_EINKBWR::~DFRobot_EINKBWR()
{}

void DFRobot_EINKBWR::begin(const char cs_W21, const char cs_GT30, const char dc)
{
    SPI.begin();
    DFR_W21_CS =cs_W21; DFR_W21_DC =dc;  DFR_GT30_CS = cs_GT30;
    pinMode(DFR_W21_CS, OUTPUT); 
    pinMode(DFR_W21_DC, OUTPUT);
    pinMode(DFR_GT30_CS, OUTPUT);
    eInkdev.highly = 104;//Set screen height
    eInkdev.width = 212;//Set Screen width
    eInkdev.scandir = EINK_SCAN_DIR3;//Set the default scanning direction
}

void DFRobot_EINKBWR::spiDelay(unsigned char xsp){
    unsigned char i;
    while(xsp--)
    {
        for(i=0;i<DFR_W21_SPI_SPEED;i++);
    }
}

void DFRobot_EINKBWR::spiRead(uint32_t addr, uint8_t len, char *ch)
{
    DFR_GT30_CS_0;
    DFR_W21_CS_1;
    SPI.transfer(0x0b);
    SPI.transfer(addr >> 16);
    SPI.transfer(addr >> 8);
    SPI.transfer(addr);
    SPI.transfer(0x00);
    while(len --) {
        *ch = SPI.transfer(0x00);
        ch ++;
    }
    DFR_GT30_CS_1;
}

void DFRobot_EINKBWR::spiWriteByte(unsigned char value){
    SPI.transfer(value);
}

void DFRobot_EINKBWR::wirteCmd(unsigned char command){
    spiDelay(1);
    DFR_W21_CS_0;
    DFR_GT30_CS_1;
    DFR_W21_DC_0;
    SPI.setBitOrder(MSBFIRST);
    spiWriteByte(command);
    DFR_W21_CS_1;
}

void DFRobot_EINKBWR::wirteData(unsigned char data){
    spiDelay(1);
    DFR_W21_CS_0;
    DFR_GT30_CS_1;
    DFR_W21_DC_1;
    //If the scan method is 2 or 4, send a low post, then send a high post
    if(eInkdev.scandir==EINK_SCAN_DIR2 || eInkdev.scandir==EINK_SCAN_DIR4){
        SPI.setBitOrder(LSBFIRST);
    }else{//If the scan is 1 or 3, send the high first and post the low post
        SPI.setBitOrder(MSBFIRST);
    }
    spiWriteByte(data);
    DFR_W21_CS_1;
}

void DFRobot_EINKBWR::setWindow(uint16_t x, uint16_t y){
    uint8_t hres,vres_h,vres_l;
    hres = y/8;
    hres <<= 3; 
    vres_h = x>>8;
    vres_l = x&0xff;
    wirteCmd(0x61);
    wirteData(hres);
    wirteData(vres_h);
    wirteData(vres_l);
    eInkdev.highly = y;
    eInkdev.width = x;
}

void DFRobot_EINKBWR::powerOn(void)
{
    wirteCmd(0x06);//Set the boost
    wirteData(0x17);
    wirteData(0x17);
    wirteData(0x17);
    wirteCmd(0x04);//Access to electricity
    delay(3000);//Wait for bus idle
    wirteCmd(0X00);//Set sweeping direction
    wirteData(0xc3|eInkdev.scandir);
    wirteCmd(0X50);
    wirteData(0x37);
    wirteCmd(0x30);//Set the PLL
    wirteData(0x39);
    setWindow(212,104);//Pixel setting 212*104
    wirteCmd(0x82);//Vcom setting
    wirteData (0x0a);
}

void DFRobot_EINKBWR::powerOff(void)
{
    wirteCmd(0x12);
    delay(5000);//Waiting for bus idle
    delay(10000);//Wait for refresh display
    wirteCmd(0x82);//to solve Vcom drop
    wirteData(0x00);
    wirteCmd(0x01);//power setting
    wirteData(0x02);
    wirteData(0x00);
    wirteData(0x00);
    wirteData(0x00);
    wirteCmd(0X02);//Power off
    delay(500);
}

void DFRobot_EINKBWR::picDisplay(const unsigned char *pic_bw, const unsigned char *pic_red)
{
    //The image data to be displayed is stored in the cache
    for(int i  =0; i < 2756; i++)
        DF_Display_bw[i] = pic_bw[i];
    for(int i = 0; i < 2756; i++)
        DF_Display_red[i] = pic_red[i];
}

void DFRobot_EINKBWR::disRefresh()
{
    if(eInkdev.scandir == EINK_SCAN_DIR3){
        powerOn();
        wirteCmd(0x10);
        for(int i = 0; i < 2756; i++) wirteData(~DF_Display_bw[i]);
        wirteCmd(0x11);
        wirteCmd(0x13);
        for(int i = 0; i < 2756; i++) wirteData(~DF_Display_red[i]);
        wirteCmd(0x11);
        powerOff();
    }else if(eInkdev.scandir == EINK_SCAN_DIR1){
        int16_t y=2743;
        powerOn();
        wirteCmd(0x10);
        while(y>=0){
            for(int i = 0; i < 13; i++) wirteData(~DF_Display_bw[y+i]);
            y-=13;
        }
        y=2743;
        wirteCmd(0x11);
        wirteCmd(0x13);
        while(y>=0){
            for(int i = 0; i < 13; i++) wirteData(~DF_Display_red[y+i]);
            y-=13;
        }
        wirteCmd(0x11);
        powerOff();
    }else if(eInkdev.scandir == EINK_SCAN_DIR2){
        int16_t y=2755;
        powerOn();
        wirteCmd(0x10);
        while(y>=0){
            for(int i = 0; i < 13; i++) wirteData(~DF_Display_bw[y-i]);
            y-=13;
        }
        y=2755;
        wirteCmd(0x11);
        wirteCmd(0x13);
        while(y>=0){
            for(int i = 0; i < 13; i++) wirteData(~DF_Display_red[y-i]);
            y-=13;
        }
        wirteCmd(0x11);
        powerOff();
    }else if(eInkdev.scandir == EINK_SCAN_DIR4){
        int16_t y=12;
        powerOn();
        wirteCmd(0x10);
        while(y<=2755){
            for(int i = 0; i < 13; i++) wirteData(~DF_Display_bw[y-i]);
            y+=13;
        }
        y=2755;
        wirteCmd(0x11);
        wirteCmd(0x13);
        while(y<=2755){
            for(int i = 0; i < 13; i++) wirteData(~DF_Display_red[y-i]);
            y+=13;
        }
        wirteCmd(0x11);
        powerOff();
    }
}

InkScreen_Error DFRobot_EINKBWR::clear(uint8_t color)
{
    uint8_t bw,red;
    if(color == WHITE){
        bw = 0x00; red = 0x00;
    }else if(color == RED){
        bw = 0x00; red = 0xff;
    }else if(color == BLACK){
        bw = 0xff; red = 0x00;
    }else{
        Serial.println("no color!");
        return false;
    }
    for(int i = 0; i < 2756; i++){
        DF_Display_bw[i]=bw;
        DF_Display_red[i]=red;
    }
    disRefresh();
    return true;
}

InkScreen_Error DFRobot_EINKBWR::drawPoint(const unsigned char x, const unsigned char y, const unsigned char color)
{
    uint8_t sx,sy;
    uint16_t sby;
    if(x>211 || y>103){
        Serial.println("Out of display!");
        return false;
    }
    sx = 211-x;      sby = sx*13;
    sy = (y+1)/8;    sby += sy;
    sy = (y+1)%8;
    if(color == RED){//Red dot
        if(sy != 0){
            DF_Display_bw[sby] &= (~(int)pow(2,8-sy)); 
            DF_Display_red[sby] |= ((int)pow(2,8-sy)); 
        }else{
            DF_Display_bw[sby-1] &= 0xFE;
            DF_Display_red[sby-1] |= 0x01;
        }
        return true;
    }else if(color == BLACK){//Black spots
        if(sy != 0){
            DF_Display_red[sby] &= (~(int)pow(2,8-sy)); 
            DF_Display_bw[sby] |= ((int)pow(2,8-sy)); 
        }else{
            DF_Display_red[sby-1] &= 0xFE;
            DF_Display_bw[sby-1] |= 0x01;
        }
        return true;
    }else if(color == WHITE){//White dots
        if(sy != 0){
            DF_Display_bw[sby] &= (~(int)pow(2,8-sy)); 
            DF_Display_red[sby] &= (~(int)pow(2,8-sy)); 
        }else{
            DF_Display_bw[sby-1] &= 0xFE;
            DF_Display_red[sby-1] &= 0xFE;
        }
        return true;
    }else if(color == LUCENCY){
        return true;
    }
    else return false;
}

InkScreen_Error DFRobot_EINKBWR::drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t color)
{
    InkScreen_Error Status = true;
    uint16_t t;
    int xerr=0,yerr=0,delta_x,delta_y,distance;
    int incx,incy,uRow,uCol;
    delta_x=x2-x1;
    delta_y=y2-y1;
    uRow=x1;
    uCol=y1;
    if(delta_x>0){
        incx=1;
    }else if(delta_x==0){
        incx=0;
    }else{
        incx=-1;delta_x=-delta_x;
    }
    if(delta_y>0){
        incy=1;
    }else if(delta_y==0){
        incy=0;
    }else{
        incy=-1;delta_y=-delta_y;
    }
    if( delta_x>delta_y){
        distance=delta_x;
    }else{
        distance=delta_y;
    }
    for(t = 0; t <= distance+1; t++ ){
        Status = drawPoint(uRow, uCol, color);
        if(!Status) return Status;
        xerr+=delta_x ;
        yerr+=delta_y ;
        if(xerr>distance){
            xerr-=distance;
            uRow+=incx;
        }
        if(yerr>distance){
            yerr-=distance;
            uCol+=incy;
        }
    }
    return Status;
}

InkScreen_Error DFRobot_EINKBWR::drawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t color)
{
    InkScreen_Error Status = true;
    Status = drawLine(x1,y1,x2,y1,color);
    if(!Status) return Status;
    Status = drawLine(x1,y1,x1,y2,color);
    if(!Status) return Status;
    Status = drawLine(x1,y2,x2,y2,color);
    if(!Status) return Status;
    Status = drawLine(x2,y1,x2,y2,color);
    if(!Status) return Status;
    return Status;
}

InkScreen_Error DFRobot_EINKBWR::rectangleFill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t color)
{
    InkScreen_Error Status = true;
    uint8_t sx=x1,sy=y1;
    for(sy = y1; sy <= y2; sy++){
        for(sx = x1; sx <= x2; sx++){
            Status=drawPoint(sx, sy, color);
            if(!Status) return Status;
        }
    }
    return Status;
}

InkScreen_Error DFRobot_EINKBWR::drawCirclePoint( uint16_t xc, uint16_t yc, uint16_t x, uint16_t y, uint8_t color)
{
    InkScreen_Error Status = true;
    uint8_t Ix=1,Iy=1;
    for(uint8_t i = 0; i < 8; i++){
        if(i<4){
            Status = drawPoint(xc + x*Ix, yc + y*Iy, color);
            if(!Status) return Status;
        }else{
            Status = drawPoint(xc + y*Ix, yc + x*Iy, color);
            if(!Status) return Status;
        }
        Ix *= -1;
        if((i+1)%2==0){
            Iy *= -1;
        }
    }
    return Status;
}

InkScreen_Error DFRobot_EINKBWR::drawCircle(uint16_t xc, uint16_t yc, uint16_t r, uint16_t fill, uint8_t color)
{
    InkScreen_Error Status = true;
    int x=0, y=r, yi,d;
    d = 3-2*r;
    if(xc-r<0 || xc+r >= eInkdev.width || yc-r < 0 || yc+r >= eInkdev.highly) return false;
    while(x<=y){
        if(fill){
            for(yi = x; yi <= y; yi++)
                Status = drawCirclePoint(xc, yc, x, yi, color);
        }else{
            Status = drawCirclePoint(xc, yc, x, y, color);
        }
        if(!Status) return Status;
        if(d<0) d = d+4*x+6;
        else {d = d+4*(x-y); y--;}
        x++;
    }
    return Status;
}

InkScreen_Error DFRobot_EINKBWR::unicodeToGB2312(char *unicode, char *GB2312) 
{
    uint32_t addr;
    uint8_t result=0;
    uint32_t h;
    uint32_t code;
    code = *unicode++;
    code = (code<<8) + *unicode;
    if(code<0x4e00||code>0x9FBF){
      for(int i = 0; i < 1000; i++){
        if(ucs_gb2312_table[i][0]==code){
          GB2312[0] = ucs_gb2312_table[i][1]>>8;
          GB2312[1] = ucs_gb2312_table[i][1];
          return true;
        }
      }
    }
    else if(code<0xa0) result=1;
    else if(code<=0xf7) h=code-160;
    else if(code<0x2c7) result=1;
    else if(code<=0x2c9) h=code-160-463;
    else if(code<0x2010) result=1;
    else if(code<=0x2312) h=code-160-463-7494;
    else if(code<0x2460) result=1;
    else if(code<=0x2642) h=code-160-463-7494-333;
    else if(code<0x3000) result=1;
    else if(code<=0x3017) h=code-160-463-7494-333-2493;
    else if(code<0x3220) result=1;
    else if(code<=0x3229) h=code-160-463-7494-333-2493-520;
    else if(code<0x4e00) result=1;
    else if(code<=0x9b54) h=code-160-463-7494-333-2493-520-7126;
    else if(code<0x9c7c) result=1;
    else if(code<=0x9ce2) h=code-160-463-7494-333-2493-520-7126-295;
    else if(code<0x9e1f) result=1;
    else if(code<=0x9fa0) h=code-160-463-7494-333-2493-520-7126-295-316;
    else if(code<0xe76c) result=1;
    else if(code<=0xe774) h=code-160-463-7494-333-2493-520-7126-295-316-18379;
    else if(code<0xff00) result=1;
    else if(code<=0xff5f) h=code-160-463-7494-333-2493-520-7126-295-316-18379-6027;
    else if(code<0xffe0) result=1;
    else if(code<=0xffe5) h=code-160-463-7494-333-2493-520-7126-295-316-18379-6027-128;
    else result=1;
    if(result==0){
        addr = UNICODETOGB2312_ADDR + (h<<1);
        //Get the gb2312 encoding from the address
        spiRead(addr, 2, GB2312);
    } else {
        GB2312[0] = 0xa1;
        GB2312[1] = 0xa1;
    }
    return true;
}

uint32_t DFRobot_EINKBWR::GB2312_addr(char *ch, uint8_t type)
{
    uint32_t temp = 0;
    if(ch[0]<0x80){
        if( ch[0] >= ' ' ){
            temp = ch[0] - ' ';
        }
        if( type == CHARACTER_TYPE_8 ){//7*8 ascii code
            temp = temp*8  + ASC0808D2HZ_ADDR;
        }else if( type == CHARACTER_TYPE_12 ){//6*12 ascii code
            temp = temp*12 + ASC0812M2ZF_ADDR;
        }else if( type == CHARACTER_TYPE_16 ){//8*16 ascii code
            temp = temp*16 + GBEX0816ZF_ADDR;
        }
    }else{
        if(ch[0] >=0xA4 && ch[0] <= 0Xa8 && ch[1] >=0xA1){
            temp = JFLS1516HZ_ADDR;
        }else if(ch[0] >=0xA1 && ch[0] <= 0Xa9 && ch[1] >=0xA1){
            temp =( (ch[0] - 0xA1) * 94 + (ch[1] - 0xA1))*32+ JFLS1516HZBD_ADDR;//Punctuation section
        }else if(ch[0] >=0xB0 && ch[0] <= 0xF7 && ch[1] >=0xA1){
            temp = ((ch[0] - 0xB0) * 94 + (ch[1] - 0xA1)+ 846)*32+ JFLS1516HZ_ADDR;
        }
    }
    return temp;
}

void DFRobot_EINKBWR::disStr(uint8_t x, uint8_t y, char *ch, uint8_t color) 
{
    char unicode_hz[2] = {0};
    char gb2312_hz [2] = {0};
    char temp_char[2] = {0};
    char str_null[32] = {0};
    int temp = 0;
    //The input character is in utf-8 format
    if(character_type == CHARACTER_TYPE_UTF8 || character_type == CHARACTER_TYPE_GB2312) {
        while(*ch) {
            if((*ch & 0xf0) == 0xe0) {//Chinese
                temp = (*ch & 0x0f) << 12 | (*(ch + 1) & 0x3f) << 6 | (*(ch + 2) & 0x3f);
                unicode_hz[0] = temp >> 8;
                unicode_hz[1] = temp;
                unicodeToGB2312(unicode_hz, gb2312_hz);
                getLattice(gb2312_hz, CHINESE_TYPE_1616, str_null);//Getting font
                showStr(x, y, CHINESE_TYPE_1616, str_null, color);//Refresh the cache
                x+=16;
                if(x+16>209){
                    x=2; y += 18;
                    if(y+16 > 101) break;
                }
                ch += 3;
            }else if((*ch & 0x80) == 0x80){
                gb2312_hz[0] = *ch;
                gb2312_hz[1] = *(ch+1);
                //unicodeToGB2312(unicode_hz, gb2312_hz);
                getLattice(gb2312_hz, CHINESE_TYPE_1616, str_null);//Getting font
                showStr(x, y, CHINESE_TYPE_1616, str_null, color);//Refresh the cache
                x+=16;
                if(x+16>209){
                    x=2; y += 18;
                    if(y+16 > 101) break;
                }
                ch += 2;
            }else{//ASCII
                temp_char[0] = *ch;
                getLattice(temp_char, CHARACTER_TYPE_16, str_null);//Getting font
                showStr(x, y, CHARACTER_TYPE_16, str_null, color);//Refresh the cache
                x+=8;
                if(x+8>209){
                    x=2; y += 18;
                    if(y+16 > 101) break;
                }
                ch++;
            }
        }
    }else if(character_type == CHARACTER_TYPE_UNICODE){
        //The input character is in unicode format
        Serial.println(strlen(ch));
    }
}

InkScreen_Error DFRobot_EINKBWR::getLattice(char *gb2312, uint8_t size, char *ch2)
{
    if(size == CHINESE_TYPE_1616){//Get 16 * 16 Chinese font
        uint32_t addr = GB2312_addr(gb2312, CHINESE_TYPE_1616);
        spiRead(addr, 32, ch2);
    }else if(size == CHARACTER_TYPE_16){//Gets 8 * 16ASCII character font
        uint32_t addr = GB2312_addr(gb2312, CHARACTER_TYPE_16);
        spiRead(addr, 16, ch2);
    }
}

InkScreen_Error DFRobot_EINKBWR::showStr(uint8_t x, uint8_t y, uint8_t size, char *ch, uint8_t color)
{
    uint8_t sx=x,font;
    uint16_t MAXfont, width;
    //16*16 Chinese display cache refresh
    if(size == CHINESE_TYPE_1616){
        MAXfont = 32; width = 16;
    }else if(size == CHARACTER_TYPE_16){
        //8*16 ASCII display cache refresh
        MAXfont = 16; width = 8;
    }
    for(int j = 0; j < MAXfont; j++){
        font=(uint8_t) ch[j];
        for(int i = 0; i < 8; i++){
            if(font&0x80) drawPoint(sx,y,color);
            else drawPoint(sx,y,LUCENCY);
            font<<=1; sx++;
            if((sx-x)==width){
                sx=x; y++;
            }
        }
    }
}

// !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxwz{|}~
//Pixel cache
//     2743            0
//		|\   |\   |\   |
//		| \  | \  | \  |
//		|  \ |  \ |  \ |
//		|   \|   \|   \|
//     2755            12

