/*
 *
 * NeoPixels minimal demo
 *
 */

#include <SPI.h>
#include <NeoPixels_SPI.h>

const unsigned int PIXELS = 8; // Number of pixels in the string

void setup ()
  {
  ledsetup();
  showColor (PIXELS, 0xB2, 0x22, 0x22);  // firebrick
  } // end of setup

void loop ()
  {
  } // end of loop
