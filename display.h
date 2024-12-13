#ifndef DISPLAY_H
#define DISPLAY_H
#include <arduino.h>

//Tässä kohdassa määritettään arduinon pinnit, joita tarvitaan 7-segment näyttöjen ohjaamiseen
#define reset 12  //MR
#define shiftClock 11 //SHCP
#define latchClock 10 //STCP
#define outEnable 9 //OE
#define serialInput 8 //DS

void initializeDisplay(void); //aliohjelmassa alustetaan arduinon käyttämät pinnit

void writeByte(uint8_t number, bool last); //aliohjelma lähettää tarvittavan tiedon 74hc595 piirille, jotta haluttu numero voidaan tulostaa

void writeHighAndLowNumber(uint8_t tens,uint8_t ones); //aliohjelma tulostaa showResult() aliohjelmaan annetun luvun (ensin tulostetaan ykköset, sitten kymmenet)

void showResult(byte result); //aliohjelmalla saadaan haluttu luku näkyviin näytölle, komento myös irrottaa kymmenet ja ykköset toisistaan ja lähettää ne writeHighAndLowNumber() aliohjelmaan

void clearDisplay(void); //aliohjelmaa voidaan käyttää jos halutaan ettei display näytä yhtään mitään

#endif