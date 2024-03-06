


#include <iostream>
#include "DigitalRain.h"

int main() {
    const int screenWidth = 120;
    const int screenHeight = 25;
    const int raindropFrequency = 20;
    const int asciiRangeStart = 33;
    const int asciiRangeEnd = 126;

    DigitalRain digitalRain(screenWidth, screenHeight, raindropFrequency, asciiRangeStart, asciiRangeEnd);
    digitalRain.start();

    return 0;
}