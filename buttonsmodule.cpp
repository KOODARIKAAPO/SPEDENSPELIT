 #include "buttonsmodule.h"

  
  byte interruptButton = 0;    //napin painallus
  byte startButton = 4;// starttinapin numero
  unsigned long previousTime = 0;   //edellinen aika
  const unsigned long debounceTime = 175; //debounce aika
  bool gameStatus = false;   //pelin tila
  bool timeToCheckGameStatus = false; //muuttuja tutkii pelin tilaa


  void initButtonsAndButtonInterrupts(void) {
    for (int i = 2; i < 7; i++) {//for-loopissa käydöön pinnit 2-6 läpi
      pinMode(i, INPUT_PULLUP);//alustaa pinnit input pullup tilaan
    }
    PCICR = (1 << PCIE2);
    PCMSK2 = (1 << PCINT18) | (1 << PCINT19) | (1 << PCINT20) | (1 << PCINT21) | (1 << PCINT22);//kesketykset alustetaan
  }

  ISR(PCINT2_vect) {
 
    unsigned long currentTime = millis();//tallennetaan muuttujan nykyaika
    
    if ((currentTime - previousTime) > debounceTime) { //suoritetaan jos on kulunut tarpeeksi aikaa edellisen napin painalluksesta
      for (int i = 2; i < 7; i++) {//käydään läpi pinnit
        if (digitalRead(i) == LOW) {//uetaan mikä pinni aiheuttaa keskeytyksen
          interruptButton = i-2;//tallennetaan muuttujaan keskeytyksen aiheutunut nappi
          //Serial.println(interruptButton);//debugaamiseen käytetty 
          if (interruptButton == startButton) { 
            interruptButton = -1;//startnappia ei lueta pelinapiksi
          }
            timeToCheckGameStatus = true;
          }
        }        
      
      previousTime = currentTime;   
      //break;
      }
    }
  
  

