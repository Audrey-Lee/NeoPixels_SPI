/*
 * 
 * NeoPixels demo - fades colours (in array) up and down
 * 
 */

#include <SPI.h>
#include <NeoPixels_SPI.h>

const unsigned int PIXELS = 8; // Number of pixels in the string

void setup()
  {
  ledsetup();
  } // end of setup
  
float patterns [] [3] = {
  { 1, 0, 0 },  // red
  { 0, 1, 0 },  // green
  { 0, 0, 1 },  // blue
  { 1, 1, 0 },  // yellow
  { 1, 0, 1 },  // magenta
  { 0, 1, 1 },  // cyan
  { 1, 1, 1 },  // white
  { 160.0 / 256, 82.0 / 256, 45.0 / 256 },  // sienna
  { 46.0 / 256, 139.0 / 256, 87.0 / 256 },  // sea green
  
};

// number of items in an array
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

void loop() 
  {
     
  for (byte i = 0; i < ARRAY_SIZE (patterns); i++) 
    {
    // fade up
    for (byte m = 0; m < 100; m++)
      {
      showColor (PIXELS, patterns [i] [0] * m, patterns [i] [1] * m, patterns [i] [2] * m);
      delay (10);
      } // end of for

    // fade down
    for (byte m = 100; m > 0; m--)
      {
      showColor (PIXELS, patterns [i] [0] * m, patterns [i] [1] * m, patterns [i] [2] * m);
      delay (10);
      } // end of for
    } // end of for each array item
        
  } // end of loop

