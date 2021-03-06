#include "buzzer.h"
#include "stateMachines.h"
void state_advance_buzzer(){
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
