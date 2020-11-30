#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcd.h"
int music   = 0;
char on      = 0;
char dimLight= 0;
char dimLevel= 0;
char party   = 0;

extern int switchAs(int state);
extern int switchAs2();
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
      if(music==2 || music ==0)
	{
	  music=1;
	}
      else if(music==1)
	{
	  music=2;
	}
    }else{
      music=0;
      mainMenu();

      }

    break;
    
  case 3:
    if(party){
      party=0;
    }else{
      party=1;
    }
  }
}

/*
  while(party) {
    while (!redrawScreen) { 
      P1OUT &= ~LED_GREEN;
      or_sr(0x10);     
    }
    P1OUT |=LED_GREEN;
    redrawScreen = 0;
    movLayerDraw(&ml0, &layer0);
  }
}

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
int statebuzzer(){
  static int state1=-1;
  if(state1==15){
      state1=-1;
    }
    state1++;
    return state1;
}
void state_advance(){
  static int state=-1;
  if(music==1){
    if(state==15){
      state=-1;
    }
    state++;
    
    switchAs(state);
  }
  else if(music==2){
    if(switchAs2()==1){
      music=1;
    }
  }
  else{
    buzzer_set_period(0);
  }
}

