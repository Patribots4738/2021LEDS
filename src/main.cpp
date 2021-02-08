#include <Arduino.h>
#include <FastLED.h>
#define FASLED_INTERNAL

#define NUM_LEDS 70
#define LED_PIN 10

CRGB j_leds[NUM_LEDS] ={0};

//#include "Marquee.h"
//#include "Twinkle.h"
//#include "Comet.h"
//#include "Bounce.h"
#include "Test.h"

#define ARRAYSIZE(x) (sizeof(x)/sizeof(x[0]))
#define TIMES_PER_SECOND(x) EVERY_N_MILLISECONDS(1000/x)

void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(j_leds, NUM_LEDS);
  FastLED.setBrightness(100);

  //FastLED.setMaxPowerInMilliWatts(1000);

}

void loop() {
 
  FastLED.clear();

  // fill_rainbow(j_leds, NUM_LEDS, initialHue += hueDensity, deltaHue);
  // delay(50);
  
  //DrawMarquee();
  //DrawTwinkle();
  //DrawComet();

  runTest();
  
  FastLED.delay(15);

}


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