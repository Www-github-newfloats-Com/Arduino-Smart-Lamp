#include "Adafruit_NeoPixel.h"

#ifdef __AVR__
#include <avr/power.h>
#endif

#define SONG_PIN 3
#define LED_PIN 8
#define NUMPIXELS 16

/*
  Colors LED cables: GREEN -> DATA; WHITE -> POWER; ORAGE -> GROUND
*/

// defines variables
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

byte R = 0;
byte G = 0;
byte B = 0;

int controller = 1;

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

    setAll(255, 255, 255);
  }
}

// -----------------------------------------------------------------------------------

void setup()
{

  Serial.begin(9600);
  pixels.begin();

  pinMode(SONG_PIN, INPUT);

  effect_default();
}

void loop()
{

  if (digitalRead(SONG_PIN) == HIGH)
  {
    switch (controller)
    {

      case 1:
        setAll(255, 0, 0); // red
        controller++;
        break;

      case 2:
        setAll(0, 255, 0); // green
        controller++;
        break;

      case 3:
        setAll(0, 0, 255); // blue
        controller++;
        break;

      case 4:
        setAll(80, 0, 80); // purple
        controller++;
        break;

      case 5:
        // setAll(255, 192, 203); // pink
        setAll(255, 140, 0); // orange
        controller = 1;
        break;

      default:
        break;
    }


    delay(500);

  }
}
