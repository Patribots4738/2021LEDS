// Draws a movie theatre style Marquee but in color

#include<Arduino.h>
#include<FastLED.h>
#include<PrecisionDraw.h>

void DrawMarqueeOld() {
    static byte j = 0;
    j += 4;
    byte k= j;

    //following is roughly equivalent to fill_rainbow(j_LEDs, NUM_LEDS, j, 8)

    CRGB c;
    for (int i = 0; i < NUM_LEDS; i++) {
        j_leds[i] = c.setHue (k+=8);
    }
    static int scroll = 0;
    scroll++;

    for(int i=scroll % 5; i < NUM_LEDS - 1; i +=5) {
        j_leds[i] = CRGB::Black;
    }
   delay(50); 
}

#define NUM_COLORS 5
static const CRGB MarqueeColors [NUM_COLORS] = {

    CRGB::Red,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Green,
    CRGB::Orange,
    
};

void DrawMarquee() {

  static int const blockWidth = 5;    //Sets roughly the ammount of leds total in the marquee

  static float scroll = 0.0f;
  scroll += 0.1f;
  
    
  if (scroll > blockWidth) {
    scroll -= blockWidth;
    }

  for(float i = scroll; i < NUM_LEDS; i += blockWidth) {
    DrawPixels(i, blockWidth - 2, CRGB::DarkBlue);
    
    }

}