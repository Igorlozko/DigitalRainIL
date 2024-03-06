#pragma once
#ifndef DIGITALRAIN_H
#define DIGITALRAIN_H

#include <vector>
#include "Raindrop.h"

class DigitalRain {
private:
    const int screenWidth;
    const int screenHeight;
    const int raindropFrequency;
    const int asciiRangeStart;
    const int asciiRangeEnd;
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<char>> nextGrid;
    std::vector<std::vector<int>> verticalDisplacement;

public:
    DigitalRain(int width, int height, int frequency, int start, int end);

    void start();
};

#endif // DIGITALRAIN_H

/*
   i include the necessary headers vector for using vector and other 

   Digital rain class holds the functionality of the digital rain effect
   Private memebrs: screenWidth: Holds the width of the screen.
                    screenHeight: Holds the height of the screen.
                    raindropFrequency: Determines the frequency of raindrops.
                    asciiRangeStart: Specifies the starting ASCII value for generating random characters.
                    asciiRangeEnd: Specifies the ending ASCII value for generating random characters.
                    grid: Represents the current state of the screen as a grid of characters.
                    nextGrid: Represents the next state of the screen after raindrops have fallen.
                    verticalDisplacement: Represents the vertical displacement of raindrops, which is currently unused in the provided code.
    Public methods: DigitalRain(int width, int height, int frequency, int start, int end): Constructor that initializes the DigitalRain object with the specified parameters.
                    start(): Method that starts the digital rain effect by continuously updating the state of the screen and rendering the raindrops.

*/
