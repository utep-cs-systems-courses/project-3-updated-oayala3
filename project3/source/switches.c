#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"

char switch_state_down, switch_state_changed; /* effectively boolean */
char button;
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
  button=2;
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

void switch_interrupt_handler()
{
  button=20;
  int p2val = p2sw_read();
  if      (1 & p2val){
    button = 0;}
  if (2 & p2val){
    button = 1;}
  if (4 & p2val){
    button = 2;}
  if (8 & p2val){
    button = 3;}
  else {
    button =0;
  }

  state_advance_buttons();
  switch_update_interrupt_sense();
}


