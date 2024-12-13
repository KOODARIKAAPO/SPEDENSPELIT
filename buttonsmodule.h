#ifndef BUTTONSMODULE_H
#define BUTTONSMODULE_H
#include <Arduino.h>

  extern int userIndex;
  extern byte userNumbers[];
  extern byte interruptButton;    
  extern byte startButton;
  extern unsigned long previousTime;   
  extern const unsigned long debounceTime; 
  extern bool gameStatus;   
  extern bool timeToCheckGameStatus;

  void initButtonsAndButtonInterrupts(void);//alustaa napit input pullup tilaan

 
  
  ISR(PCINT2_vect);//napin kesketyspalvelija


  #endif