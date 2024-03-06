


#include <iostream>
#include "DigitalRain.h"

int main() {
    const int screenWidth = 120;
    const int screenHeight = 25;
    const int raindropFrequency = 25;
    const int asciiRangeStart = 33;
    const int asciiRangeEnd = 126;

    DigitalRain digitalRain(screenWidth, screenHeight, raindropFrequency, asciiRangeStart, asciiRangeEnd);
    digitalRain.start();

    return 0;
}

/*
I include the necessary header files iostream for input and output and DigitalRain header

Main initializes the parameters such as screenWidth, screenHeight, raindropFrequency, asciiRangeStart, asciiRangeEnd

Digital rain obkect line 14 instance of the digital rain class created with specific parametes 
responsible for generating and rendering the digital rain effect

start method runs indefinetly controlled byt he while(true) updating constantly 

*/