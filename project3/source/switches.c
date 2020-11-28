#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"
#include "../p2swLib/p2switches.h"

char switch_state_down, switch_state_changed; /* effectively boolean */

char button;
  
static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  u_int p2val = p2sw_read();

  if      ((p2val) == 1)
    button = 0;
  else if ((p2val) == 2)
    button = 1;
  else if ((p2val) == 4)
    button = 2;
  else if ((p2val) == 8)
    button = 3;

  state_advance_buttons();
 
}
