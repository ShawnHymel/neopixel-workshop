#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 8

// Data pin connected to NeoPixel strip
#define DATA_PIN 3

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 

  // Scan one way
  for ( int n = 0; n < NUM_LEDS; n++ ) {
    drawLED(n);
    delay(100);
  }

  // Scan the other way
  for ( int n = NUM_LEDS - 1; n > -1; n-- ) {
    drawLED(n);
    delay(100);
  }
}

// Function to draw all the LEDs
void drawLED(int led_pos) {
  for ( int i = 0; i < NUM_LEDS; i++ ) {
    if ( i == led_pos ) {
      leds[i].red = 100;
      leds[i].green = 10;
    } else {
      leds[i].red = 0;
      leds[i].green = 0;
    }
  }
  FastLED.show();
}
