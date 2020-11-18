#include "Adafruit_NeoPixel.h"

#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN 7
#define NUMPIXELS 16

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

byte R = 0;
byte G = 0;
byte B = 0;
int freq = 1000;

// -----------------------------------------------------------------------------------

void setPixel(int pixel, byte red, byte green, byte blue)
{
  pixels.setPixelColor(pixel, pixels.Color(red, green, blue));
}

// -----------------------------------------------------------------------------------

void setAll(byte red, byte green, byte blue)
{
  for (int i = 0; i < NUMPIXELS; i++)
  {
    setPixel(i, red, green, blue);
  }
  pixels.show();
}

// -----------------------------------------------------------------------------------

void effect_default()
{
  pixels.clear();
  for (int j = 0; j < 3; j++)
  {

    // Fade IN
    for (int k = 0; k < 256; k++)
    {
      switch (j)
      {
        case 0:
          setAll(k, 0, 0);
          break;
        case 1:
          setAll(0, k, 0);
          break;
        case 2:
          setAll(0, 0, k);
          break;
      }
      pixels.show();
      delay(5);
    }

    // Fade OUT
    for (int k = 255; k >= 0; k--)
    {
      switch (j)
      {
        case 0:
          setAll(k, 0, 0);
          break;
        case 1:
          setAll(0, k, 0);
          break;
        case 2:
          setAll(0, 0, k);
          break;
      }
      pixels.show();
      delay(5);
    }
  }
}

// -----------------------------------------------------------------------------------

void setup()
{

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  Serial.begin(9600);
  pixels.begin();
  effect_default();
}

void loop()
{
  if (Serial.available())
  {
    R = Serial.readStringUntil(',').toInt();
    G = Serial.readStringUntil(',').toInt();
    B = Serial.readStringUntil(',').toInt();
    freq = Serial.readStringUntil(',').toInt();
  }

  setAll(R, G, B);
  delay(freq);
  setAll(0, 0, 0);
  delay(freq);

}
