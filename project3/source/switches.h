#ifndef switches_included
#define switches_included

#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1|SW2|SW3|SW4)
typedef unsigned char u_char;
typedef unsigned int u_int;

unsigned int p2sw_read();

void p2sw_init(unsigned char mask);
unsigned int p2sw_read();
void switch_interrupt_handler();
extern char switch_state_down, switch_state_changed, button; /* effectively boolean */

#endif // included
