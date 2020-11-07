#include "Adafruit_NeoPixel.h"

#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 7
#define NUMPIXELS 16

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAY_NORMAL 10000
#define DELAY_FAST 50

void setup()
{

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  Serial.begin(9600);    // Taxa de transmissão na serial

  pixels.begin();
  pixels.clear();

  /* for (int i = 0; i < NUMPIXELS; i++)
    {
     pixels.setPixelColor(i, pixels.Color(0, 0, 255));
     pixels.show();
    }*/

  pixels.setPixelColor(0, pixels.Color(255, 150, 0));
  pixels.setPixelColor(1, pixels.Color(0, 150, 0));
  pixels.setPixelColor(2, pixels.Color(0, 150, 0));
  pixels.setPixelColor(3, pixels.Color(0, 150, 255));
  pixels.setPixelColor(4, pixels.Color(0, 150, 0));
  pixels.setPixelColor(5, pixels.Color(0, 150, 0));
  pixels.setPixelColor(6, pixels.Color(255, 150, 0));
  pixels.setPixelColor(7, pixels.Color(0, 150, 0));
  pixels.setPixelColor(8, pixels.Color(0, 150, 0));
  pixels.setPixelColor(9, pixels.Color(0, 150, 0));
  pixels.setPixelColor(10, pixels.Color(0, 150, 255));
  pixels.setPixelColor(11, pixels.Color(0, 150, 255));
  pixels.setPixelColor(12, pixels.Color(0, 150, 255));
  pixels.setPixelColor(13, pixels.Color(0, 150, 0));
  pixels.setPixelColor(14, pixels.Color(0, 150, 0));
  pixels.setPixelColor(15, pixels.Color(0, 150, 0));
  pixels.show();

}

void loop()
{

  if ( Serial.available() )
  {
    Serial.println("recebeu:");
    Serial.println(Serial.readString());
    pixels.clear();
  }

  // Mostra os valores lidos, na serial
  //Serial.print("Temp. = ");

}
