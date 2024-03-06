


#include <iostream>
#include "DigitalRain.h"

int main() {
    const int screenWidth = 120; // Adjust as needed
    const int screenHeight = 25; // Adjust as needed
    const int raindropFrequency = 5; // Adjust the frequency of raindrops (increase for more raindrops)
    const int asciiRangeStart = 33; // Start of the ASCII range for random characters
    const int asciiRangeEnd = 126; // End of the ASCII range for random characters

    DigitalRain digitalRain(screenWidth, screenHeight, raindropFrequency, asciiRangeStart, asciiRangeEnd);
    digitalRain.start();

    return 0;
}