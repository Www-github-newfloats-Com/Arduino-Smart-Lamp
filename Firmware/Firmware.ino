#include "Controller.h"

//#ifdef __AVR__
//#include <avr/power.h>
//#endif

#define SONG_PIN 3

void setup() {
  Serial.begin(9600);
  initController();
  pinMode(SONG_PIN, INPUT);
}

void loop() {

  if (Serial.available()) {
    String[] index = Serial.readString().substring("-");
    // say what you got:
    Serial.print("I received: ");
    Serial.println(index[0]);
    //setColorIndex(index);
    //loopSelectColorByIndex();
    //delay(2000);
  } else {

  }

  //loopSelectColorByIndex();
  delay(500);

  //    if (digitalRead(SONG_PIN) == HIGH) {
  //        delay(500);
  //    }
}
