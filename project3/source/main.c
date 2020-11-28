#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
void main(void) 
{  
  configureClocks();
  led_init();
  buzzer_init();
  p2sw_init(15);
  lcd_init();
  enableWDTInterrupts();
  or_sr(0x8);
  or_sr(0x18);  // CPU off, GIE on
}
