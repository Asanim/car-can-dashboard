// The following is example / workshop code from http://www.jczn1688.com/ 
// Obtained from the following URL: http://pan.jczn1688.com/directlink/1/ESP32%20module/1.28inch_ESP32-2424S012.zip
// This is demo code pre loaded on the development board: https://www.aliexpress.com/item/1005005561489118.html

#include "Arduino.h"
#include "lvgl.h"
#include "ui.h"

//set up the touch screen
#define is_touch 0
//set up the auto play
#define is_auto_play 1
//set up the now_auto play
extern int now_is_auto_play;

void ui_mian(void);
void auto_play(void);
