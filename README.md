NeoPixel Workshop
=================

This is a very brief introduction to using the digital, multi-colored LEDs known as "NeoPixels" with Arduino and the [FastLED library](http://fastled.io/). For a full write-up on using NeoPixels, please see the [wonderful Uberguide by Adafruit](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels).

 Note that this guide assumes you are using the venerable WS2812b LEDs.

The code, text, and images are licensed under [Creative Commons Attribution 4.0 International](https://creativecommons.org/licenses/by/4.0/) (unless otherwise specified, e.g., in code libraries).

### Required Parts

 * [Arduino UNO](https://store.arduino.cc/usa/arduino-uno-rev3) (or similar clone)
 * [NeoPixel Strip](https://www.adafruit.com/product/1376?length=1) (must be WS2812-based for the code shown)
 * [Breadboard](https://www.adafruit.com/product/64)
 * [300-500 Ohm Resistor](https://www.adafruit.com/product/2781)
 * [Jumper Wires](https://www.adafruit.com/product/758)
 * [Potentiometer](https://www.adafruit.com/product/356)

### Required Software

You will need the Arduino IDE. Head to [arduino.cc](https://www.arduino.cc/) and follow the directions to install Arduino.

Once in Arduino, you will need the **FastLED** library. Go to **Sketch > Include Library > Manage Libraries**. Search for and install "FastLED."

### Demo 1: Blinky

Connect the NeoPixel strip to the Arduino as shown. Note the use of the 330 Ohm resistor between pin 3 and the DIN line of the NeoPixel strip. Additionally, we are only going to use 8 of the LEDs on the strip. If you plan to use more, you will likely need to use an external power supply and add a 1000 uF decoupling capacitor, as shown in the [diagram on this page](https://learn.adafruit.com/adafruit-neopixel-uberguide/basic-connections).

