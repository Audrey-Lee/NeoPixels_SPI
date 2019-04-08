#include <SPI.h>
#include<msp432.h>
void sendByte (char b);
void ledsetup();
void sendPixel (const char r, const char g, const char b);
void show();
void showColor (const unsigned int count, const char r , const char g , const char b);
