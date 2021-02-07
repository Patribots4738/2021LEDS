#include <Arduino.h>
#include <FastLED.h>
#define FASLED_INTERNAL

#define NUM_LEDS 70
#define LED_PIN 10

CRGB j_leds[NUM_LEDS] ={0};

//#include "Marquee.h"
#include "Twinkle.h"
#include "Comet.h"
#include "Bounce.h"

#define ARRAYSIZE(x) (sizeof(x)/sizeof(x[0]))
#define TIMES_PER_SECOND(x) EVERY_N_MILLISECONDS(1000/x)
/*
//Fractional Color
//
// Returns a fraction of a color; abststracts the fadeToBlack out to this function in case we
// want to improve the color math or do color math all in one location.

CRGB ColorFraction(CRGB colorIn, float fraction) {

  fraction = min(1.0f, fraction);
  return CRGB(colorIn).fadeToBlackBy(225 * (1.0f - fraction));

}

void DrawPixels(float fPos, float count, CRGB color) {

  // Calclulate how much the first pixel will hold
  float availFirstPixel = 1.0f - (fPos - (long)(fPos));
  float amtFirstPixel = min(availFirstPixel, count);
  float remaining = min(count, FastLED.size() - fPos);
  int iPos = fPos;

  // Blend in the color of the first partial pixel

  if (remaining > 0.0f)
  {
    FastLED.leds() [iPos++] += ColorFraction(color, amtFirstPixel);
    remaining -= amtFirstPixel;
  }

  // Now draw pixels in the middle
  while (remaining > 1.0f)
  {
    FastLED.leds() [iPos++] += color;
    remaining--;
  }
  
  // Draw tail pixel, up to a single pixel
  if (remaining > 0.0f)
  {
    FastLED.leds() [iPos] += ColorFraction(color, remaining);
  }
  
}

void DrawMarqueeBetter() {

  static float scroll = 0.0f;
  scroll += 0.1f;
    
  if (scroll > 5.0) {
    scroll -= 5.0;
    }

  for(float i = scroll; i < NUM_LEDS; i += 5) {
    DrawPixels(i, 3, CRGB::Red);
    }
  
  //delay(50);

}
*/

void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(j_leds, NUM_LEDS);
  FastLED.setBrightness(100);

  //FastLED.setMaxPowerInMilliWatts(1000);

}

void loop() {
 
  //FastLED.clear();

  // fill_rainbow(j_leds, NUM_LEDS, initialHue += hueDensity, deltaHue);
  // delay(50);
  
  //DrawMarquee();
  //DrawTwinkle();
  DrawComet();
  
  FastLED.delay(10);

}