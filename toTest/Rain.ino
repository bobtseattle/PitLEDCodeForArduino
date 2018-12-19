#include <FastLED.h>
#define NUM_LEDS 144
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop()
{
  rain(0,0,255,30, NUM_LEDS/2);
  rain(255,0,0,30,0);
}

void rain(byte red, byte green, byte blue, int d, int center)
{
  for (int dot = 0; dot < NUM_LEDS/2; dot++)
  {
    leds[(center + dot) %NUM_LEDS] = CRGB( red, green, blue); // set this pixel to color
    leds[(center-dot)%144] = CRGB(red, green, blue);
    FastLED.show();
    delay(d);
  }
}
/*
  //Example 1: set color from red, green, and blue components individually
  // The three color channel values can be referred to as "red", "green", and "blue"...
    leds[i].red   = 50;
    leds[i].green = 100;
    leds[i].blue  = 150;
  // ...or, using the shorter synonyms "r", "g", and "b"...
    leds[i].r = 50;
    leds[i].g = 100;
    leds[i].b = 150;
  // ...or as members of a three-element array:
    leds[i][0] = 50;  // red
    leds[i][1] = 100; // green
    leds[i][2] = 150; // blue
  //Example 2: set color from red, green, and blue components all at once
  leds[i] = CRGB( 50, 100, 150);
  // Example 3: set color via 'hex color code' (0xRRGGBB)
  leds[i] = 0xFF007F;
  // Example 4: set color via any named HTML web color
  leds[i] = CRGB::HotPink;
  // Example 5: set color via setRGB
  leds[i].setRGB( 50, 100, 150);
*/
