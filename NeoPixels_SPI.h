#include <SPI.h>
void sendByte (byte b);
void ledsetup();
void sendPixel (const byte r, const byte g, const byte b);
void show();
void showColor (const unsigned int count, const byte r , const byte g , const byte b);
