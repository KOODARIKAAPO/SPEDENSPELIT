#include "buzzer.h"
//ääniä tuottava ohjelma
void initializeBuzzer(){
  pinMode(tonePin, OUTPUT);
}

void failSound(){
  tone(tonePin, NOTE_AS3, 300);
  delay(350);
  tone(tonePin, NOTE_F3, 600);
  delay(800);
  noTone(tonePin);
}

void winSound(){
  tone(tonePin, NOTE_C4, 100);
  delay(100);
  tone(tonePin, NOTE_E4, 100);
  delay(100);
  tone(tonePin, NOTE_G4, 100);
  delay(200);
  noTone(tonePin);
}

void win10Sound(){
  tone(tonePin, NOTE_C4, 100);
  delay(100);
  tone(tonePin, NOTE_D4, 100);
  delay(100);
  tone(tonePin, NOTE_E4, 100);
  delay(100);
  tone(tonePin, NOTE_F4, 100);
  delay(100);
  tone(tonePin, NOTE_G4, 100);
  delay(100);
  tone(tonePin, NOTE_A4, 100);
  delay(100);
  tone(tonePin, NOTE_B4, 100);
  delay(100);
  tone(tonePin, NOTE_C5, 100);
  delay(200);
  noTone(tonePin);
}

void victorySound(){
  tone(tonePin, NOTE_G4, 200);
  delay(300);
  tone(tonePin, NOTE_G4, 200);
  delay(250);
  tone(tonePin, NOTE_G4, 200);
  delay(300);
  tone(tonePin, NOTE_C5, 1200);
  delay(1400);
  noTone(tonePin);
}

void highscoreSound(){
  tone(tonePin, NOTE_F4, 100);
  delay(200);
  tone(tonePin, NOTE_F4, 100);
  delay(150);
  tone(tonePin, NOTE_F4, 100);
  delay(200);
  tone(tonePin, NOTE_A4, 600);
  delay(800);
  noTone(tonePin);
}

void startSound(){
  tone(tonePin, NOTE_C4, 500);
  delay(1000);
  tone(tonePin, NOTE_C4, 500);
  delay(1000);
  tone(tonePin, NOTE_C4, 500);
  delay(1000);
  tone(tonePin, NOTE_C5, 500);
  delay(600);
  noTone(tonePin);
}