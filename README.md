# NeoPixels done with SPI

Intended for Adafruit NeoPixels (800 kHz version).

Run from an Arduino Uno / Mega or similar running at 16 MHz clock speed.

## Connection

Since this library uses SPI for the precise timing needed, the data pin for the NeoPixels is MOSI.

* On the Uno that is pin D11 (digital pin 11)
* On the Mega that is D51
* On other boards like the Leonardo you will need to pick up MOSI from the ICSP header

## How to use

### ledsetup ();

* Get ready to send.
* Call once at the beginning of the program.

### sendPixel (r, g, b);

Send a single pixel to the string.

* Call this once for each pixel in a frame.
* Each colour is in the range 0 to 255.

### show ();

* Latch the recently sent pixels onto the LEDs .
* Call once per frame.

### showColor (count, r, g, b);

* Set the entire string of count Neopixels to this one colour.
* This automatically turns interrupts off, so you don't need to do it yourself.

---

Note that if you are sending individual pixels (with sendPixel) you should first call
noInterrupts(), send all the pixels you need, and then call interrupts(). Otherwise a timer or
other interrupt may pause the sending long enough for the string to reset.

For example:

```C++
    noInterrupts ();          // prevent interrupts while we are sending colours
    for (byte i = 0; i < 10; i++)
      {
      sendPixel (100, 0, 0);    // red
      sendPixel (0, 100, 0);    // green
      sendPixel (0, 0, 100);    // blue
      } // end of for loop
    interrupts ();            // interrupts are OK now
    show ();                  // latch the colours
```

---

## More information

The forum post [Simple method for using NeoPixels](http://www.gammon.com.au/forum/?id=13357) has a lot of details and explanations.
