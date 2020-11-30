#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */

  static char blink_count = 0;
  static char blink_light = 0;
  static char change_dim  = 0;
  if (++blink_count == 75) {
    state_advance();
    //    lcd_state();
    blink_count = 0;
  }
  if(++blink_light==1){
    dim25();
    dim75();
    blink_light = 0;
  }
  if(++change_dim==125){
    dim_machine();
    change_dim = 0;
    dim_machine();
  }
  static short count = 0;
  P1OUT |= GREEN_LED;      /**< Green LED on when cpu on */
  count ++;
  if (count == 15) {
    mlAdvance(&ml0, &fieldFence);
    if (p2sw_read())
    redrawScreen = 1;
    count = 0;
  }
  P1OUT &= ~GREEN_LED;
}
