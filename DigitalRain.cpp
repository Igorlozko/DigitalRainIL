#include "DigitalRain.h"
#include <iostream>
#include <cstdlib> // For rand() function
#include <ctime>   // For seeding srand()
#include <thread>  // For std::this_thread::sleep_for

DigitalRain::DigitalRain(int width, int height, int frequency, int start, int end)
    : screenWidth(width), screenHeight(height), raindropFrequency(frequency), asciiRangeStart(start), asciiRangeEnd(end),
    grid(height, std::vector<char>(width, ' ')), nextGrid(height, std::vector<char>(width, ' ')) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void DigitalRain::start() {
    while (true) {
        // Update the next grid with new raindrops
        for (int x = 0; x < screenWidth; ++x) {
            if (rand() % 100 < raindropFrequency) {
                int startY = rand() % screenHeight;
                if (startY < screenHeight) {
                    nextGrid[startY][x] = rand() % (asciiRangeEnd - asciiRangeStart + 1) + asciiRangeStart;
                }
            }
        }

        // Render the raindrops without clearing the screen
        for (int y = 0; y < screenHeight; ++y) {
            for (int x = 0; x < screenWidth; ++x) {
                if (nextGrid[y][x] != ' ') {
                    // Move cursor to position (x, y)
                    std::cout << "\x1B[" << y + 1 << ";" << x * 4 + 1 << "H"; // ANSI escape codes, *4 to add more space between characters
                    // Set color to green
                    std::cout << "\x1B[32m    " << nextGrid[y][x] << "\x1B[0m"; // ANSI escape codes for green color, add larger spaces before the character
                }
            }
        }

        // Swap grids
        grid.swap(nextGrid);

        // Move raindrops down gradually
        for (int y = screenHeight - 1; y > 0; --y) {
            for (int x = 0; x < screenWidth; ++x) {
                nextGrid[y][x] = grid[y - 1][x];
            }
        }

        // Clear the top row of the next grid
        for (int x = 0; x < screenWidth; ++x) {
            nextGrid[0][x] = ' ';
        }

        // Sleep to control the speed of the rain
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}