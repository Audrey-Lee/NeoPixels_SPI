/*
 * 
 * NeoPixels demo - colours extend along strip
 * 
 */

#include <SPI.h>
#include <NeoPixels_SPI.h>

const unsigned int PIXELS = 300; // Number of pixels in the string

void setup()
  {
  ledsetup();
  } // end of setup

void colourTransition (const byte from_r, const byte from_g, const byte from_b,
                       const byte to_r,   const byte to_g,   const byte to_b)
  {
  // draw one more of the desired colour, each time around the loop
  for (unsigned int iteration = 0; iteration < PIXELS; iteration++) 
    {
    noInterrupts ();
    for (unsigned int pixel = 0; pixel < PIXELS; pixel++) 
      {
      if (pixel < iteration)
         sendPixel (to_r, to_g, to_b);
      else
         sendPixel (from_r, from_g, from_b);
      }
    interrupts ();
    show ();  // latch this iteration in
    } // end of each iteration
  }
  
void loop() 
  {
  colourTransition (0, 0, 0, 255, 0, 0);    // black to red
  colourTransition (255, 0, 0, 0, 255, 0);  // red to green
  colourTransition (0, 255, 0, 0, 0, 255);  // green to blue
  colourTransition (0, 0, 255, 0, 0, 0);    // blue back to black
  } // end of loop

