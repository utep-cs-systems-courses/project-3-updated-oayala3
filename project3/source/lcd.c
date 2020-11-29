#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "lcd.h"

void mainMenu(){
  clearScreen(COLOR_BLUE);
  
  drawString5x7(1,5, "Main Menu", COLOR_RED, COLOR_BLUE);
  fillRectangle(10, 20, 110, 20, COLOR_GREEN);
  drawString5x7(15,25, "Turn on RED LED", COLOR_GREEN, COLOR_BLUE);
  fillRectangle(10, 50, 110, 20, COLOR_RED);
  drawString5x7(15,55, "DIM red LED",COLOR_RED, COLOR_BLUE);
  fillRectangle(10, 80, 110, 20, COLOR_RED);
  drawString5x7(15,85, "Turn on song", COLOR_RED, COLOR_BLUE);
  fillRectangle(10, 110, 110, 20, COLOR_GREEN);
  drawString5x7(15,115, "Screen Party", COLOR_GREEN, COLOR_BLUE);
 
  
  
}
void redON(){
  clearScreen(COLOR_BLUE);
  
  drawString5x7(1,5, "RED is ON", COLOR_RED, COLOR_BLUE);
  fillRectangle(10, 20, 110, 20, COLOR_GREEN);
  drawString5x7(15,25, "Turn off RED LED", COLOR_GREEN, COLOR_BLUE);
  fillRectangle(10, 50, 110, 20, COLOR_GREEN);
  drawString5x7(15,55, "DIM red LED",COLOR_GREEN, COLOR_BLUE);
  fillRectangle(10, 80, 110, 20, COLOR_GREEN);
  drawString5x7(15,85, "Turn on song", COLOR_GREEN, COLOR_BLUE);
  fillRectangle(10, 110, 110, 20, COLOR_GREEN);
  drawString5x7(15,115, "Screen Party", COLOR_GREEN, COLOR_BLUE);
  
}


void dimON(){
  clearScreen(COLOR_BLUE);

  
  drawString5x7(1,5, "RED is ON && Dim", COLOR_RED, COLOR_BLUE);
  fillRectangle(10, 20, 110, 20, COLOR_GREEN);
  drawString5x7(15,25, "Turn off RED LED", COLOR_GREEN, COLOR_BLUE);
  fillRectangle(10, 50, 110, 20, COLOR_GREEN);
  drawString5x7(15,55, "stop DIM red LED",COLOR_GREEN, COLOR_BLUE);
  fillRectangle(10, 80, 110, 20, COLOR_RED);
  drawString5x7(15,85, "Turn on song", COLOR_RED, COLOR_BLUE);
  fillRectangle(10, 110, 110, 20, COLOR_GREEN);
  drawString5x7(15,115, "Screen Party", COLOR_GREEN, COLOR_BLUE);
  
}


void songONLightON(){
  clearScreen(COLOR_BLUE);
  
  drawString5x7(1,5, "RED is ON && music", COLOR_RED, COLOR_BLUE);
  fillRectangle(10, 20, 110, 20, COLOR_GREEN);
  drawString5x7(15,25, "Turn off RED LED", COLOR_GREEN, COLOR_BLUE);
  fillRectangle(10, 50, 110, 20, COLOR_GREEN);
  drawString5x7(15,55, "stop DIM red LED",COLOR_GREEN, COLOR_BLUE);
  fillRectangle(10, 80, 110, 20, COLOR_RED);
  drawString5x7(15,85, "Turn on song", COLOR_RED, COLOR_BLUE);
  fillRectangle(10, 110, 110, 20, COLOR_GREEN);
  drawString5x7(15,115, "Screen Party", COLOR_GREEN, COLOR_BLUE);
  
}


void songONLightOFF(){
  clearScreen(COLOR_BLUE);
  
  drawString5x7(1,5, "RED is Off && Music", COLOR_RED, COLOR_BLUE);
  fillRectangle(10, 20, 110, 20, COLOR_GREEN);
  drawString5x7(15,25, "Turn on RED LED", COLOR_GREEN, COLOR_BLUE);
  fillRectangle(10, 50, 110, 20, COLOR_RED);
  drawString5x7(15,55, "stop DIM red LED",COLOR_RED, COLOR_BLUE);
  fillRectangle(10, 80, 110, 20, COLOR_RED);
  drawString5x7(15,85, "Turn off song", COLOR_RED, COLOR_BLUE);
  fillRectangle(10, 110, 110, 20, COLOR_GREEN);
  drawString5x7(15,115, "Screen Party", COLOR_GREEN, COLOR_BLUE);
  
}


