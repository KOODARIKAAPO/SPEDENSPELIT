
#include "SpedenSpelit.h"
#include "leds.h"
#include "buttonsmodule.h"
#include "display.h"
#include "buzzer.h"
//kommentoitu hederiin
int score;
bool gameSatus = false;
int interruptCount;
int interruptRate = 20;
int interruptTime;

void setup() {
  
  initializeBuzzer();
  initializeLeds();
  initializeDisplay();
  initButtonsAndButtonInterrupts();
  Serial.begin(9600);
  Serial.println("setup done");
  
}

void initializeTimer(void) {
  cli();  // Disable global interrupts

  // Kellon setup
  TCCR1A = 0;  // timer a alustetaan
  TCCR1B = 0;  // timer b alustetaan
  TCNT1 = 0;   // timer Counter moodi 0


  OCR1A = 6249;  // output compare arvo

  //CTC moodi päälle (Clear Timer on Compare Match)
  TCCR1B |= (1 << WGM12);

  // prescaler 256
  TCCR1B |= (1 << CS12);

  // Enable Timer1 compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei();  // Enable global interrupts
}

void loop() {
  if (gameStatus == false) {
       showResult(highScore);
      if(digitalRead(6)==LOW){
      Serial.println("Start game");
      startTheGame();//aloitusnapin painallus aloittaa pelin
    }
  }

  if (timeToCheckGameStatus == true) {
      checkGame(interruptButton);//napin painallus vie pelin check game aliohjelmaan
      timeToCheckGameStatus = false;
  }  
  if(interruptTime > interruptRate &&gameStatus == true){//jos pelaaja ei saa napinpainallusta oikeaan aikaan, hän häviää pelin
    stopGame();
    score = 0;
  }
}
 
 ISR(TIMER1_COMPA_vect) {
  if(gameStatus == true){
    interruptTime++;//tuo interrupteja joiden aikaikkunaan napinpainallus tulee onnistua
      
  
  
  if (interruptCount >= 10) {
    interruptCount = 0; 
    tenth = true;
    OCR1A = OCR1A*0.9 ; 
      // Lisää taajuutta (nopeuta keskeytyksiä)
  }
}

 }

void checkGame(byte interruptButton) {
  if (randomNumber == interruptButton && interruptTime <= interruptRate){ //asettaa ehdon, napinpainalluksen täytyy olla sama kuin arvottu numero
    if (gameStatus){
      score += 1;//lisää pisteen onnistuneesta painalluksesta
      
      if (tenth = true){//jos 10 oikeaa napinpainallusta, pieni ääni efekti
          win10Sound();
          tenth = false; 
      }
    else {
        winSound();//onnistunut napinpainallus ääni joka painalluksella
    }
      interruptCount += 1;//interrupt coun inkrementoidaan kun painallus onnistuu
      clearAllLeds();
      showResult(score);
      delay(600);
      randomNumber = random(0,4); 
      setLed(randomNumber);
      interruptTime=0;
      

    }
  } 
  
  else {
    stopGame();//jos painallus epäonnistuu, häviää pelin
    score = 0;
  }
}


void initializeGame() {//aletaan arpomaan numeroita ja ledishow pyörii
  blinkLEDs();
  randomNumber = random(0,4);
   setLed(randomNumber);
  interruptTime=0;
  interruptCount=0;
}

void startTheGame() {//laitetaan taimeri ja peli päälle
  gameStatus = true;
  initializeTimer();
  initializeGame();
}

void stopGame(void) {//kun pelaaja häviää pelin, asetetaan pelistatus pois päältä ja tutkitaan oliko pistyemäärä uusi ennätys ja ledit vilkahtavat
  gameStatus = false;
  failSound();
  if (score > highScore){
    highscoreSound();
     highScore = score;
  }
  clearAllLeds();
  gameOver();
  TIMSK1 |= (0 << OCIE1A);//pysäyttää taimerin
}


