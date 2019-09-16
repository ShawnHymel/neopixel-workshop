#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 8

#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 

  // Set all LEDs to one color
  for ( int i = 0; i < NUM_LEDS; i++ ) {
    leds[i].red = 100;
    leds[i].green = 10;
    leds[i].blue = 100;
  }
  FastLED.show();

  // Wait
  delay(500);

  // Turn off LEDs
  for ( int i = 0; i < NUM_LEDS; i++ ) {
    leds[i].red = 0;
    leds[i].green = 0;
    leds[i].blue = 0;
  }
  FastLED.show();

  // Wait
  delay(500);
}
