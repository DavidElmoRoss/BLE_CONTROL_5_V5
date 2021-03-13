/*
    Title:  Uses Control Pad to turn on RED, GREEN, BLUE, internal Leds
    Author: Dave Ross
    Date:   Sep 6th, 2017
    Description:    
*/

#include "mbed.h"               // include the mbed library
#include "Grove_LCD_RGB_Backlight.h"
Grove_LCD_RGB_Backlight rgbLCD(D14, D15);
Serial blue(D1,D0);             // blue is of class serial associated with UART
int main()
{
    char bnum=0;                // set button # to zero and shut off RGB leds
     
    while(1) {                  // set up infinte loop
        if (blue.getc()=='!') {
            if (blue.getc()=='B') { //button data
                bnum = blue.getc(); //button number
                if ((bnum>='5')&&(bnum<='8')) //is a number button 1..8
                {
                    switch(bnum)
                    {
                        case '5':   rgbLCD.setRGB(0x00, 0xff, 0x00);
                                    break;
                        case '6':   rgbLCD.setRGB(0xff, 0x00, 0x00);
                                    break;
                        case '7':   rgbLCD.setRGB(0xff, 0xff, 0xff);
                                    break;
                        default:   rgbLCD.setRGB(0x00, 0x00, 0xff);
                                    
                                    break;
                        
                    }
                }
            }
        }
    }
}
