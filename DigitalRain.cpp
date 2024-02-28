#include <iostream>
#include <vector>
#include <cstdlib> // For rand() function
#include <ctime>   // For seeding srand()
#include <thread>  // For std::this_thread::sleep_for

#include "DigitalRain.h"

DigitalRain::DigitalRain() {
    // Initialize DigitalRain object
    srand(time(nullptr)); // Seed random number generator
}

void DigitalRain::start() {
    const int screenWidth = 80; // Adjust as needed
    const int screenHeight = 25; // Adjust as needed

    std::vector<std::vector<char>> grid(screenHeight, std::vector<char>(screenWidth, ' ')); // Initialize all elements to ' '

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
            if (rand() % 100 < 20) { // Adjust the probability as needed
                int length = rand() % 10 + 1; // Random length between 1 and 10
                for (int y = 0; y < length; ++y) {
                    if (y < screenHeight) {
                        grid[y][x] = '.'; // Use different characters for raindrops for visual variety
                    }
                }
            }
        }

        // Render the raindrops
        for (int y = 0; y < screenHeight; ++y) {
            for (int x = 0; x < screenWidth; ++x) {
                std::cout << grid[y][x];
            }
            std::cout << std::endl;
        }

        // Shift all raindrops down by one position
        for (int y = screenHeight - 1; y > 0; --y) {
            for (int x = 0; x < screenWidth; ++x) {
                grid[y][x] = grid[y - 1][x];
            }
        }

        // Clear the top row
        for (int x = 0; x < screenWidth; ++x) {
            grid[0][x] = ' ';
        }

        // Sleep for a short duration to control the speed of the rain
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
