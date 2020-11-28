#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcd.h"
#include "stateMachines.h"
#define LED_GREEN BIT6             // P1.6


short redrawScreen = 1;
u_int fontFgColor = COLOR_GREEN;

static int faceID=1;
void wdt_c_handler()
{
  static int secCount = 0;

  secCount ++;
  if (secCount == 250) {		/* once/sec */
    secCount = 0;
    fontFgColor = (fontFgColor == COLOR_GREEN) ? COLOR_BLACK : COLOR_GREEN;
    
    if(faceID){
      faceID=0;
    }else{
      

      faceID=1;
    }
    lcd_state();
    redrawScreen = 1;
  }
}
  

void main()
{
  P1DIR |= LED_GREEN;		/**< Green led on when CPU on */		
  P1OUT |= LED_GREEN;
  configureClocks();
  lcd_init();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(COLOR_BLUE);
  while (1) {			/* forever */
    if (redrawScreen) {
      redrawScreen = 0;
        fillRectangle(10, 20, 110, 20, COLOR_RED);
 drawString5x7(15,25, "Main Menu", COLOR_RED, COLOR_BLUE);
      fillRectangle(10, 50, 110, 20, COLOR_RED);
 drawString5x7(15,55, "Turn On RED LED",COLOR_RED, COLOR_BLUE);
      fillRectangle(10, 80, 110, 20, COLOR_RED);
 drawString5x7(15,85, "DIM Red LED", COLOR_RED, COLOR_BLUE);
      fillRectangle(10, 110, 110, 20, COLOR_RED);
 drawString5x7(15,115, "Screen Party", COLOR_RED, COLOR_BLUE);
    }
    P1OUT &= ~LED_GREEN;	/* green off */
    or_sr(0x10);		/**< CPU OFF */
    P1OUT |= LED_GREEN;		/* green on */
  }
}

    
    



