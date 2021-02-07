// Draws random colored stars on LED strip for a Twinkly effect

#include<Arduino.h>
#include<FastLED.h>



#define NUM_COLORS 5
static const CRGB TwinkleColors [NUM_COLORS] = {

    CRGB::Red,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Green,
    CRGB::Orange,
    
};

void DrawTwinkleOld() {

    FastLED.clear(false);   //CLear the strip, but dont push the bits out

    for (int i=0; i<NUM_LEDS / 4; i++) {

        j_leds[random(NUM_LEDS)] = TwinkleColors[random(NUM_COLORS)];
        FastLED.show();
        delay(200);

    }
}

void DrawTwinkle() {

    static int passCount = 0;
    passCount++;

    // Every time passCount his a quarter of the LED total, We reset the Strip
    if (passCount == NUM_LEDS) {
        
        passCount = 0;
        FastLED.clear(false);
    
    }
    
    j_leds[random(NUM_LEDS)] = TwinkleColors[random(NUM_COLORS)];
        delay(30);


}