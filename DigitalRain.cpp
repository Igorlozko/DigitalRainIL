#include "DigitalRain.h"
#include <iostream>
#include <cstdlib> // For rand() function
#include <ctime>   // For seeding srand()
#include <thread>  // For std::this_thread::sleep_for

DigitalRain::DigitalRain(int width, int height, int frequency, int start, int end)
    : screenWidth(width), screenHeight(height), raindropFrequency(frequency), asciiRangeStart(start), asciiRangeEnd(end) {
    // Initialize grid with spaces
    grid = std::vector<std::vector<char>>(screenHeight, std::vector<char>(screenWidth, ' '));
    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
}

void DigitalRain::start() {
    // ANSI escape codes
    const std::string clearScreen = "\x1B[2J\x1B[H"; // Clear screen
    const std::string hideCursor = "\x1B[?25l"; // Hide cursor
    const std::string showCursor = "\x1B[?25h"; // Show cursor

    // Hide cursor
    std::cout << hideCursor << std::flush;

    while (true) {
        // Update the grid with new raindrops
        for (int x = 0; x < screenWidth; ++x) {
            if (rand() % 100 < raindropFrequency) {
                int startY = rand() % screenHeight;
                if (startY < screenHeight) {
                    grid[startY][x] = rand() % (asciiRangeEnd - asciiRangeStart + 1) + asciiRangeStart; // Generate a random ASCII character
                }
            }
        }

        // Move the raindrops down
        for (int y = screenHeight - 1; y > 0; --y) {
            for (int x = 0; x < screenWidth; ++x) {
                grid[y][x] = grid[y - 1][x];
            }
        }

        // Clear the top row of the grid
        for (int x = 0; x < screenWidth; ++x) {
            grid[0][x] = ' ';
        }

        // Render the raindrops
        for (int y = 0; y < screenHeight; ++y) {
            for (int x = 0; x < screenWidth; ++x) {
                std::cout << grid[y][x];
            }
            std::cout << std::endl;
        }

        // Sleep for a short duration to control the speed of the rain
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        // Move cursor to the beginning of the screen
        std::cout << "\x1B[" << screenHeight << "A"; // Move up 'screenHeight' lines
        std::cout << "\x1B[" << screenWidth << "D";  // Move left 'screenWidth' characters

        // Clear the screen
        std::cout << clearScreen << std::flush;
    }

    // Show cursor
    std::cout << showCursor;
}