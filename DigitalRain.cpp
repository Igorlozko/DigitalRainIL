#include <iostream>
#include <vector>
#include <cstdlib> // For rand() function
#include <ctime>   // For seeding srand()
#include <thread>  // For std::this_thread::sleep_for

#include "DigitalRain.h"

DigitalRain::DigitalRain() {
    // Initialize DigitalRain object
    srand(static_cast<unsigned int>(time(nullptr))); // Seed random number generator with the current time
}

void DigitalRain::start() {
    const int screenWidth = 80; // Adjust as needed
    const int screenHeight = 25; // Adjust as needed
    const int raindropFrequency = 20; // Adjust the frequency of raindrops (increase for more raindrops)
    const int asciiRangeStart = 33; // Start of the ASCII range for random characters
    const int asciiRangeEnd = 126; // End of the ASCII range for random characters

    std::vector<std::vector<char>> grid(screenHeight, std::vector<char>(screenWidth, ' ')); // Initialize all elements to space

    while (true) {
        // Clear the screen
        system("cls || clear");

        // Render the cloud at the top
        for (int x = 0; x < screenWidth; ++x) {
            if (x >= 20 && x <= 60) {
                std::cout << '~'; // Represent cloud with '~' character
            }
            else {
                std::cout << ' '; // Empty space for the rest of the screen
            }
        }
        std::cout << std::endl;

        // Update the grid with new raindrops
        for (int x = 0; x < screenWidth; ++x) {
            if (rand() % 100 < raindropFrequency) { // Adjust the probability as needed
                int startY = rand() % screenHeight; // Random starting position at the top
                if (startY < screenHeight) {
                    grid[startY][x] = rand() % (asciiRangeEnd - asciiRangeStart + 1) + asciiRangeStart; // Generate a random ASCII character
                }
            }
        }

        // Render the raindrops
        for (int y = 0; y < screenHeight; ++y) {
            for (int x = 0; x < screenWidth; ++x) {
                if (grid[y][x] != ' ') {
                    // Set the color to green
                    std::cout << "\x1B[32m" << grid[y][x] << "\x1B[0m"; // ANSI escape codes for green color
                }
                else {
                    std::cout << ' '; // Empty space if no raindrop
                }
            }
            std::cout << std::endl;
        }

        // Clear the grid for next frame
        for (int y = 0; y < screenHeight; ++y) {
            for (int x = 0; x < screenWidth; ++x) {
                grid[y][x] = ' ';
            }
        }

        // Sleep for a short duration to control the speed of the rain
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}