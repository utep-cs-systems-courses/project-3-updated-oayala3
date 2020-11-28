#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcd.h"

char music   = 0;
char on      = 0;
char dimLight= 0;
char dimLevel= 0;

void turn_on(){
  red_on      = 1;
  green_on    = 1;
  led_changed = 1;
  on          = 1;
  led_update();
}

void turn_off(){
  red_on      = 0;
  green_on    = 0;
  led_changed = 1;
  on          = 0;
  led_update();
}

void dim_machine(){
  if(dimLight){
    static int state = 1;
    switch(state){
    case 1:
      dim25();
      dimLevel = 0;
      state++;
      break;
    case 2:
      dim75();
      dimLevel = 1;
      state = 1;
      break;
    }
  }
}

void dim25(){
  if(dimLight){
    if(!dimLevel){
     static int state = 1;  
      switch(state){
      case 1:
	turn_off();
      state++;
      break;
      case 2:
	turn_on();
	state = 1;
	break;
      }
    }
  }
}

void dim75(){
  if(dimLight){
    if(dimLevel){
      static int state=1;  
      switch(state){
      case 1:
      case 2:
      case 3:
	turn_off();
	state++;
	break;
      case 4:
	turn_on();
	state = 1;
	break;
      }
    }
  }
}

void state_advance_buttons(){
  switch(button){
  case 0:
    turn_on();
    break;
  case 1:
    turn_off();
    break;
  case 2:
    if(dimLight)
      dimLight=0;
    else
      dimLight=1;
    break;
  case 3:
    if(on)
      music=1;
    else
      music=0;
    break;
  }
}
void lcd_state(){
  if(on && music){
    songONLightON();
  }else if(!on && music){
    songONLightOFF();
  }else if(!on && !music){
    mainMenu();
  }else if(dimLight){
    dimON();
  }else{
    mainMenu();
  }
}

void state_advance(){
  static int state=-1;
  if(music){
    state++;
    switch(state){
    case 0:  buzzer_set_period(7124); break;
    case 1:  buzzer_set_period(7124); break;
    case 2:  buzzer_set_period(4992); break;
    case 3:  buzzer_set_period(4992); break;
    case 4:  buzzer_set_period(4545); break;
    case 5:  buzzer_set_period(4545); break;
    case 6:  buzzer_set_period(4992); break;
    case 7:  buzzer_set_period(5714); break;
    case 8:  buzzer_set_period(5714); break;
    case 9:  buzzer_set_period(5664); break;
    case 10: buzzer_set_period(5664); break;
    case 11: buzzer_set_period(6660); break;
    case 12: buzzer_set_period(6660); break;
    case 13: buzzer_set_period(7126); break;
    case 14: buzzer_set_period(7126); break;
    case 15: state=0; break;
    }
  }
  else{
    buzzer_set_period(0);
  }
}
