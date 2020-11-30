#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"


char button=4;
static unsigned char switch_mask;
static unsigned char switches_last_reported;
static unsigned char switches_current;

static void
switch_update_interrupt_sense()
{
  switches_current = P2IN & switch_mask;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (switches_current);  /* if switch up, sense down */
  //P2IES &= (switches_current | ~switch_mask); /* if switch down, sense up */
}


void p2sw_init(unsigned char mask)
{
  switch_mask = mask;
  P2REN |= mask;    /* enables resistors for switches */
  P2IE = mask;      /* enable interrupts from switches */
  P2OUT |= mask;    /* pull-ups for switches */
  P2DIR &= ~mask;   /* set switches' bits for input */
  switch_update_interrupt_sense();
}

unsigned int p2sw_read() {
  unsigned int sw_changed = switches_current ^ switches_last_reported;
  switches_last_reported = switches_current;
  return switches_current | (sw_changed << 8);
}
void
switch_interrupt_handler()
{
  unsigned int readSwitch=p2sw_read();
  unsigned int i;
  or_sr(0x8);
  for(i=0; i<4; i++){
    if ((readSwitch & (1<<i))==0){ /* check which button is pressed*/
      button = i;
      break;
    }
  }
  
  P1DIR |= LED_GREEN;/**< Green led on when CPU on */

  P1OUT |= LED_GREEN;
  state_advance_buttons();
  P1OUT &= ~LED_GREEN;    /**< Green led off witHo CPU */
  or_sr(0x10);      /**< CPU OFF */
  
}
void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & switch_mask) {  /* did a button cause this interrupt? */
    P2IFG &= ~switch_mask;/* clear pending sw interrupts */
    switch_update_interrupt_sense();
    switch_interrupt_handler();
  }
}
