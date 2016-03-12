#include <SPI.h>
#include <NeoPixels_SPI.h>

const unsigned int PIXELS = 8; // Number of pixels in the string

void setup()
  {
  ledsetup();
  } // end of setup

// Flashes get faster and faster until *boom* and fade to black.
void detonate(const unsigned int count,
              unsigned char r , unsigned char g , unsigned char b ,
              unsigned int startdelayms)
  {
  while (startdelayms)
    {
    showColor (count, r, g, b);      // Flash the color
    delay (50);
    showColor (count, 0, 0, 0);
    delay (startdelayms);
    startdelayms =  (startdelayms * 4) / 5 ;           // delay between flashes is halved each time until zero
    } // end of while

  // Then we fade to black....

  for (int fade = 256; fade > 0; fade--)
    {
    showColor (count, (r * fade) / 256, (g * fade) / 256, (b * fade) / 256);
    delay (1);
    } // end of for loop

} // end of detonate

void loop()
  {
  detonate(PIXELS, 255, 165, 0, 1000);  // orange
  delay (2000);
  } // end of loop
