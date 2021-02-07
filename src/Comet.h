// Draws a moving comet with fading tail

#include<Arduino.h>
#include<FastLED.h>
#include<PrecisionDraw.h>

extern CRGB j_leds [];

void DrawComet() {

    const byte fadeAmt = 100;       // Fraction of 256 to fade a pixel by if its chosen to be faded
    const int cometSize = 5;        // Size of comet in pixels
    const int deltaHue = 4;         // How far to step the cycling hue each draw
    const double cometSpeed = .5;  // How far to advance the comet every frame
    
    static byte hue = HUE_RED;      // Current color
    static int iDirection = 1;      // Current Direction
    static double iPos = 0.0;          //Current commet postition on the strip

    hue += deltaHue;                // Update compet color
    iPos += iDirection * cometSpeed;// Update comet postition
    
    //Use Precision draw to do the same thing
    DrawPixels((int)iPos, cometSize, CRGB::Azure);

    // Flip the comet direction when it hist either end
    if (iPos == (NUM_LEDS - cometSize) || iPos == 0)
        iDirection *=-1;
  
    // //Draw the comet at its current postition
    // for (int i = 0; i < cometSize; i++)
    //     j_leds[(int)iPos + i].setHue(hue);

    //Fade leds one step
    for (int j = 0; j < NUM_LEDS; j++) 
        if(random(10) > 5)
            j_leds[j] = j_leds[j].fadeToBlackBy(fadeAmt);

    


    //delay(50);

}