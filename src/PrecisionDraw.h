// This will allow us to draw fractions of pixels

#include<FastLED.h>
#include<Arduino.h>

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