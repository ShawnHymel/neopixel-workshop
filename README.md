NeoPixel Workshop
=================

This is a very brief introduction to using the digital, multi-colored LEDs known as "NeoPixels" with Arduino and the [FastLED library](http://fastled.io/). For a full write-up on using NeoPixels, please see the [wonderful Uberguide by Adafruit](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels).

 Note that this guide assumes you are using the venerable WS2812b LEDs.

### License

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

![Arduino connections to NeoPixels Fritzing](https://raw.githubusercontent.com/ShawnHymel/neopixel-workshop/master/images/demo-01_bb.png)

Upload the code found in [FastLED_Demo_01](https://github.com/ShawnHymel/neopixel-workshop/blob/master/FastLED_Demo_01/FastLED_Demo_01.ino) to your Arduino.

You should see 8 LEDs on the NeoPixel strip flash a purplish color.

**Challenge:** Play with the values of red, green, and blue to make new colors.

### Calculate NeoPixel Power Requirements

"How much power do I need?" is a common question when working with NeoPixels. While a single LED might not consume much power, when you start dealing with 100s, you start talking in Amps.

Most NeoPixels (especially the WS2812b types) require 3.5-5.3V power and similar logic (5V power and 5V logic will work fine). You might find some strips that need 12V--read the documentation and/or datasheets!

Basic LEDs can usually draw up to 20 mA each (max), and NeoPixels are no different. Each individual "pixel" is made up of 3 LEDs: one red, one green, and one blue. Therefore, each pixel can consume around 60 mA. However, that is at maximum brightness for all LEDs--pure, bright white light. If you stick to one color or reduce the brightness, then you can assume that the LEDs will consume less than that.

To calculate the total power needed for the worst-case scenario, multiply 60 mA times the number of pixels you plan to use:

total_current = 60 mA × num_pixels

As an example, if you're using a 30-pixel strip, that gives us a worst-case current draw of 60 mA × 30 = 1800 mA (or 1.8 A). Therefore, make sure you use a 5V power supply that can provide *at least* 1.8 A (more if you want to power other things, like your Arduino board).

The [NeoPixel Uberguide](https://learn.adafruit.com/adafruit-neopixel-uberguide/powering-neopixels) has a full write-up on how to calculate power needs.

### Demo 2: KITT or Cylon Chaser

Use the circuit from Demo 1, as we haven't changed any of the electronics (yet). Upload the code found in [FastLED_Demo_02](https://github.com/ShawnHymel/neopixel-workshop/blob/master/FastLED_Demo_02/FastLED_Demo_02.ino) to your Arduino.

You should see an LED chase back and forth across the LED strip (well, at least for the first 8 pixels).

**Challenge:** Make the chase pattern 3 LEDs instead of 1 LED. If you look at [photos of KITT](https://www.automobilemag.com/news/the-house-of-kitt/), you can see that more than 1 light is on at a time.

### Introducing the Potentiometer

A potentiometer is a resistor with a third element that slides across that resistor. It essentially looks like 2 resistors in series with the middle pin connecting in between them. By adjusting the knob, you can change the values of those resistors. However, the 2 resistors will always add up to the same value (e.g. 10 kOhms in our case).

By connecting 1 end to 5V and the other to GND, we can create a simple circuit where a small amount of current flows through the resistors. The middle pin is then connected to one of our ADC pins, which creates a voltage divider. By rotating the knob, we can adjust the voltage and use it to create an interface in our Arduino.

See these pages to learn more:

 * [Potentiomenters](https://www.electronics-tutorials.ws/resistor/potentiometer.html)
 * [Voltage Dividers](https://learn.sparkfun.com/tutorials/voltage-dividers/all)

### Demo 3: Knob-controlled Lights

Connect the NeoPixel strip and potentiometer to the Arduino as shown.

![Arduino connections to NeoPixels Fritzing](https://raw.githubusercontent.com/ShawnHymel/neopixel-workshop/master/images/demo-03_bb.png)

Upload the code found in [FastLED_Demo_03](https://github.com/ShawnHymel/neopixel-workshop/blob/master/FastLED_Demo_03/FastLED_Demo_03.ino) to your Arduino.

As you adjust the knob, the red channel should fade in and out, making the light warmer or cooler.

**Challenges:** 

 * Change the code so that the knob adjusts the total brightness instead of just one color
 * Add a knob to the KITT/Cylon chaser to adjust the speed
 * Make the knob cycle through colors of the rainbow (using [HSV color space](https://github.com/FastLED/FastLED/wiki/Pixel-reference#setting-hsv-colors-) instead of RGB will help a lot)