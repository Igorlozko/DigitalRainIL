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

public:
    DigitalRain(int width, int height, int frequency, int start, int end);

    void start();
};

#endif // DIGITALRAIN_H
