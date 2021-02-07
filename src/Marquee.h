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
   delay(100); 
}

#define NUM_COLORS 5
static const CRGB MarqueeColors [NUM_COLORS] = {

    CRGB::Red,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Green,
    CRGB::Orange,
    
};

const int blockSize = 5;    // How many pixels is one color block

void DrawMarquee() {

  static float scroll = 0.0f;
  scroll += 0.1f;
    
  if (scroll > 5.0) {
    scroll -= 5.0;
    }

  for(float i = scroll; i < NUM_LEDS; i += 5) {
    DrawPixels(i, 3, CRGB::Aquamarine);
    }
  
  //delay(500);

}