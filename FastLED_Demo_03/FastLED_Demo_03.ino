#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 8

// Analog pin connected to potentiometer
#define POT_PIN A0

// Data pin connected to NeoPixel strip
#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 

  // Set all LEDs to one color based on potentiometer reading
  for ( int i = 0; i < NUM_LEDS; i++ ) {
    leds[i].red = map(analogRead(POT_PIN), 0, 1023, 0, 255);
    leds[i].green = 100;
    leds[i].blue = 100;
  }
  FastLED.show();
}
