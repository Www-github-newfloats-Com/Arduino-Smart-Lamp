#include "Controller.h"

/*
  Colors LED cables: GREEN -> DATA; WHITE -> POWER; ORANGE -> GROUND
*/

// #define SONG_PIN 3

void setup()
{
    Serial.begin(9600);
    initController();

#ifdef SENSOR_SONG_PIN
    pinMode(SONG_PIN, INPUT);
#endif
}

void loop()
{

#ifdef SENSOR_SONG_PIN

    if (digitalRead(SONG_PIN) == HIGH)
    {
        selectColorByIndexMode();
        incrementIndex();
        delay(1000);
    }

#else

    christmasTreeMode();

#endif
}
