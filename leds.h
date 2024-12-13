#ifndef LEDS_H
#define LEDS_H
#include <Arduino.h>
#define tonePin 13 

// led pinnit ja niiden määrät
const int ledPins[] = {A2, A3, A4, A5};
const byte numLeds = 4;
//sizeof(ledPins) / sizeof(ledPins[0]);

// funktiot
void initializeLeds();//alustaa ledit
void setLed(byte ledNumber);
void clearAllLeds();
void setAllLeds();
void show1();//sytyttää yksittäisen ledin käyttäjän syötteen mukaan
void show2(int rounds);//valoshow
void showBinary(int num);
void displayBit(int bit, int ledPin);
void blinkLEDs();//lähtölaskenta
void gameOver();//pelihäviö valoshow

#endif