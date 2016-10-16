#include "../include/screen.h"
int cursorX = 0, cursorY = 0;
const uint8 sw = 80,sh = 25,sd = 2; 
int color = 0x0F;
const string vidmem = (string) 0xb8000;

void clearLine(uint8 from,uint8 to)
{
        uint16 i = sw * from * sd;
        for(i;i<(sw*to*sd);i++)
        {
                vidmem[(i / 2)*2 + 1 ] = color ;
                vidmem[(i / 2)*2 ] = 0;
        }
}
void updateCursor()
{
    unsigned temp;

    temp = cursorY * sw + cursorX;                                                      // Position = (y * width) +  x

    outportb(0x3D4, 14);                                                                // CRT Control Register: Select Cursor Location
    outportb(0x3D5, temp >> 8);                                                         // Send the high byte across the bus
    outportb(0x3D4, 15);                                                                // CRT Control Register: Select Send Low byte
    outportb(0x3D5, temp);                                                              // Send the Low byte of the cursor location
}
void clearScreen()
{
        clearLine(0,sh-1);
        cursorX = 0;
        cursorY = 0;
        updateCursor();
}

void scrollUp(uint8 lineNumber)
{
        uint16 i = 0;
        clearLine(0,lineNumber-1);                                            //updated
        for (i;i<sw*(sh-1)*2;i++)
        {
                vidmem[i] = vidmem[i+sw*2*lineNumber];
        }
        clearLine(sh-1-lineNumber,sh-1);
        if((cursorY - lineNumber) < 0 ) 
        {
                cursorY = 0;
                cursorX = 0;
        } 
        else 
        {
                cursorY -= lineNumber;
        }
        updateCursor();
}


void newLineCheck()
{
        if(cursorY >=sh-1)
        {
                scrollUp(1);
        }
}

void printch(char c)
{     
    switch(c)
    {
        case (0x08):
                if(cursorX > 0) 
                {
	                cursorX--;									
                        vidmem[(cursorY * sw + cursorX)*sd]=0;	     //(0xF0 & color)                          
	        }
	        break;
       /* case (0x09):
                cursorX = (cursorX + 8) & ~(8 - 1); 
                break;*/
        case ('\r'):
                cursorX = 0;
                break;
        case ('\n'):
                cursorX = 0;
                cursorY++;
                break;
        default:
                vidmem [((cursorY * sw + cursorX))*sd] = c;
                vidmem [((cursorY * sw + cursorX))*sd+1] = color;
                cursorX++; 
                break;
	
    }
    if(cursorX >= sw)                                                                   
    {
        cursorX = 0;                                                                
        cursorY++;                                                                    
    }
    updateCursor();
    newLineCheck();
}

void print (string ch)
{
        uint16 i = 0;
        uint8 length = strlength(ch);              //Updated (Now we store string length on a variable to call the function only once)
        for(i;i<length;i++)
        {
                printch(ch[i]);
        }
       /* while((ch[i] != (char)0) && (i<=length))
                print(ch[i++]);*/
        
}
void setScreenColor(int textColor,int bgColor)
{
	color =  (bgColor << 4) | textColor;;
}
void setScreenColorCode(int colorCode)
{
	color = colorCode;
}
void printColored(string ch,int textColor,int bgColor)
{
	int currentColor = color;
	setScreenColor(textColor,bgColor);
	print(ch);
	setScreenColorCode(currentColor);
}

void printFromPosition(string ch, uint8 x, uint8 y)
{
    cursorX = x;
    cursorY = y;
    updateCursor();
    print(ch);
}
void printFromPositionColor(string ch, uint8 x, uint8 y, uint8 textColor, uint8 backgroundColor)
{
    cursorX = x;
    cursorY = y;
    updateCursor();
    printColored(ch, textColor, backgroundColor);
}

