#include <Arduino.h>
#include <FastLED.h>

#define LEDPIN 10

#define NUMLEDS 52

// this has to be called z_LEDS or something gets a reference error
CRGB z_LEDS[NUMLEDS] = {0};

void setup() {

    FastLED.clear();

    pinMode(LEDPIN, OUTPUT);

    FastLED.addLeds<WS2812B, LEDPIN, GRB>(z_LEDS, NUMLEDS);
    FastLED.setBrightness(16);

}

void loop() {

    fill_solid(z_LEDS, NUMLEDS, CRGB::Azure);

    FastLED.show();

} 