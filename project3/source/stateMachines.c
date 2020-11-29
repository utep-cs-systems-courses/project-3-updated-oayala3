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
  led_changed = 1;
  //  on          = 1;
  led_update();
}

void turn_off(){
  red_on      = 0;
  led_changed = 1;
  // on          = 0;
  led_update();
}

void dim_machine(){
  if(on){
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
    if(!on){

      if(music){
	songONLightON();
      }else{
	redON();
      }
      
      turn_on();
      on=1;
      
    }else{
      turn_off();
      on=0;


      if(music){
	songONLightOFF();
      }else{
	mainMenu();
      }


    }
    break;
  case 1:
    if(on){
      if(dimLight){
	dimLight=0;
	mainMenu();
      }else{
	dimLight=1;
	dimON();
	}
    }
    break;
  case 2:
    songONLightON();
    if(on){
      music=1;
    }else{
      music=0;
      mainMenu();
    }
    break;
  }
}

/*
void lcd_state(){
  if(on && !dimLight && music){
    songONLightON();
  }else if(!on && !dimLight && music){
    songONLightOFF();
  }else if(dimLight){
    dimON();
  }else if(on && !dimLight){
    redON();
  }else{
    mainMenu();
  }
}
*/

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
