#include "leds.h"
#include"buzzer.h"
void initializeLeds() {
    // led pinnit OUTPUT
    for (int i = 0; i < numLeds; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
}

void setLed(byte ledNumber) {
    if (ledNumber < numLeds) {
        digitalWrite(ledPins[ledNumber], HIGH);
    }
}

void clearAllLeds() {
    // käy kaikkien ledien läpi ja sammuttaa
    for (int i = 0; i < numLeds; i++) {
          digitalWrite(ledPins[i], LOW);  // sammuttaa ledin

        //setLed(i); //apu funktio
    }
}

void setAllLeds() {
    // käy ledien läpi ja sytyttää ne
    for (int i = 0; i < numLeds; i++) {
        setLed(i);  
    }
}

void show1() {
    for (int num = 0; num < 16; num++) {
        showBinary(num);  // näyttää binäärin
        delay(500);
    }
}

void show2(int rounds) {
    int delayTime = 1000;  // viive alussa

    for (int round = 0; round < rounds; round++) {
        // vilkuttaa ledejä yksi kerrallaan
        for (int i = 0; i < numLeds; i++) {
            digitalWrite(ledPins[i], HIGH);
            delay(delayTime);
            digitalWrite(ledPins[i], LOW);
        }

        // pienentää aikaa seuraavalle roundille
        if (delayTime > 100) {
            delayTime -= 100;
        }
    }
}

void showBinary(int num) {
    for (int i = 3; i >= 0; i--) {
        int bit = (num >> i) & 1;
        displayBit(bit, ledPins[3 - i]);  // näyttää jokaisen bitin
    }
}

void displayBit(int bit, int ledPin) {//päättää mikä ledi syttyy 
    if (bit == 1) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
}
// ledien vilkutus
void blinkLEDs() {//Tähän tulee buzzerin pin
  tone(tonePin, NOTE_C4, 500);
  digitalWrite(A2, HIGH);
  delay(500);
  digitalWrite(A3, HIGH);
  delay(500);
  tone(tonePin, NOTE_C4, 500);
  digitalWrite(A4, HIGH);
  delay(500);
  digitalWrite(A5, HIGH);
  delay(500);
  tone(tonePin, NOTE_C4, 500);
 
  // sammutetaan ledit
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  delay(1000);
 
  // sytyttää kaikki ledit
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  digitalWrite(A5, HIGH);
  tone(tonePin, NOTE_C5, 500);
  delay(600);
 
  // sammuttaa
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  
}

void gameOver() {
  for (int i = 0; i < 3; i++) {  // toistaa 3 kertaa
    for(int x=0; x < 4; x++) {
    digitalWrite(ledPins[x], HIGH);
    delay(200);
    }

    for(int x=0; x < 4; x++) {
    digitalWrite(ledPins[x], LOW);
    delay(200);
    }
  }
}