#include "display.h"


void initializeDisplay(void)
{
  pinMode(reset, OUTPUT);
  pinMode(shiftClock, OUTPUT);
  pinMode(latchClock, OUTPUT);
  pinMode(outEnable, OUTPUT);
  pinMode(serialInput, OUTPUT);
  digitalWrite(reset, HIGH); //MR clears shift register if LOW
  digitalWrite(outEnable, LOW); //all Q outputs in Z state if OE is HIGH
}


void writeByte(uint8_t number,bool last)
{
  digitalWrite(latchClock, LOW);
  uint8_t displayNumber;
  /*Alla oleva switch case muuntaa numerot sellaiseen muotoon, että ne voidaan näyttää 7-segment näytöllä
  Hoxs! riipuen 7-segment näytön kytkemisestä 74hc595 piiriin, binaari luvut ovat erit!!
    (alla oleva taulukko on tehty periaatteella: A => Q0, B => Q1, C => Q2, ..., DP => Q7)*/
  switch (number) {
        case 0:{
          displayNumber = B11111100;
          break;
        }
        case 1:{
          displayNumber = B01100000;
          break;
        }
        case 2:{
          displayNumber = B11011010;
          break;
        }
        case 3:{
          displayNumber = B11110010;
          break;
        }
        case 4:{
          displayNumber = B01100110;
          break;
        }
        case 5:{
          displayNumber = B10110110;
          break;
        }
        case 6:{
          displayNumber = B10111110;
          break;
        }
        case 7:{
          displayNumber = B11100000;
          break;
        }
        case 8:{
          displayNumber = B11111110;
          break;
        }
        case 9:{
          displayNumber = B11110110;
          break;
        }
        default:{
          displayNumber = B00000000;
          break;
        }
    }
  shiftOut(serialInput, shiftClock,LSBFIRST, displayNumber);
  if (last==true){  //jos last on tosi, luku kirjoitetaan outputtiin (eli annettu numero on viimeinen kirjoitettava numero)
    digitalWrite(latchClock, HIGH);
  }
}


void writeHighAndLowNumber(uint8_t tens,uint8_t ones)
{
  bool last = false;
  writeByte(ones, last); //ensin kirjoitetaan ykköset (ne eivät ole viimeinen luku mikä kirjoitetaan joten last on epätosi)
  last = true;
  writeByte(tens, last); //sitten kirjoitetaan kymmenet (sen jälkeen ei tarvitse kirjoittaa enempää numeroita joten last on tosi)
}

void showResult(byte result)
{
  while (result>99){  //pidetään huolta, että kirjoitettava luku ei ole yli 99 (jos annettu arvo on 101, kirjoitetaan näytölle 02)
    result = result-99;
  } //periaatteessa ylimääräinen osa koodia riippuen kuinka gamelogic määrittää scoren joka on yli 99
  uint8_t tens = 0;
  uint8_t ones = 0;
  tens = result / 10; //irrottaa kymmenet annetusta luvusta
  ones = result % 10; //irrottaa ykköset annetusta luvusta
  writeHighAndLowNumber(tens, ones);
}

void clearDisplay(void){  //tätä komentoa voidaan käyttää jos halutaan ettei display näytä yhtään mitään
  digitalWrite(latchClock, LOW);
  shiftOut(serialInput, shiftClock, LSBFIRST, B00000000); 
  shiftOut(serialInput, shiftClock, LSBFIRST, B00000000); 
  digitalWrite(latchClock, HIGH); 
}