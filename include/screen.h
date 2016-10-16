#ifndef SCREEN_H
#define SCREEN_H
#include "system.h"
#include "string.h"
#include "color.h"
int cursorX , cursorY;
const uint8 sw ,sh ,sd ; 
const string vidmem;
                                                    //We define the screen width, height, and depth.
void clearLine(uint8 from,uint8 to);

void updateCursor();

void clearScreen();

void scrollUp(uint8 lineNumber);

void newLineCheck();

void printch(char c);

void print (string ch);
void setScreenColorCode(int colorCode);
void setScreenColor(int text_color,int bgColor);
void printColored(string ch,int textColor,int bColor);
void printFromPosition(string ch, uint8 x, uint8 y);
void printFromPositionColor(string ch, uint8 x, uint8 y, uint8 textColor, uint8 bColor);

#endif
