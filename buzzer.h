#ifndef BUZZER_H
#define BUZZER_H
#include <arduino.h>

#define tonePin 13 //Tähän tulee buzzerin pin. Muista tarkistaa, että se on oikea.

#define NOTE_F3  175
#define NOTE_AS3 233
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

void initializeBuzzer(); //asetetaan buzzerin pinni OUTPUTiksi
void failSound(); //soitetaan ääni kun pelaaja painaa väärää nappia
void winSound(); //soitetaan ääni kun pelaaja painaa oikeaa nappia
void win10Sound(); //soitetaan kun pelaaja on painanut 10 nappia peräkkäin oikein
void victorySound(); //soitetaan ääni kun pelaaja pääsee pelin loppuun (eli score on 99)
void highscoreSound(); //soitetaan ääni kun pelaaja saa muutettua highscorea
void startSound(); //soitetaan ääni kun peli alkaa (ALIOHJELMAA EI KÄYTETÄ KOODISSA VAAN SEN SISÄLTÖ SIIRRETÄÄN LEDS TIEDOSTON ALIOHJELMAAN, KOSKA ÄÄNET JA VALOT TOIMIVAT YHTÄ AIKAA)

#endif