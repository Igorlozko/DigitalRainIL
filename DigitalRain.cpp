#include "DigitalRain.h"
#include <iostream>
#include <cstdlib> // For rand() function
#include <ctime>   // For seeding srand()
#include <thread>  // For std::this_thread::sleep_for

DigitalRain::DigitalRain(int width, int height, int frequency, int start, int end)
    : screenWidth(width), screenHeight(height), raindropFrequency(frequency), asciiRangeStart(start), asciiRangeEnd(end),
    grid(height, std::vector<char>(width, ' ')), nextGrid(height, std::vector<char>(width, ' ')), 
    verticalDisplacement(height, std::vector<int>(width, 0)) {
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
                    verticalDisplacement[startY][x] = 0; // Reset vertical displacement
                }
            }
        }

        // Render the raindrops without clearing the screen
        for (int y = 0; y < screenHeight; ++y) {
            for (int x = 0; x < screenWidth; ++x) {
                if (nextGrid[y][x] != ' ') {
                    // Move cursor to position (x, y + vertical displacement)
                    std::cout << "\x1B[" << y + 1 + verticalDisplacement[y][x] << ";" << x * 4 + 1 << "H"; // ANSI escape codes, *4 to add more space between characters
                    // Set color to green
                    std::cout << "\x1B[32m    " << nextGrid[y][x] << "\x1B[0m"; // ANSI escape codes for green color, add larger spaces before the character
                    // Increment vertical displacement
                    ++verticalDisplacement[y][x];
                }
            }
        }

        // Swap grids
        grid.swap(nextGrid);

        // Move raindrops down gradually
        for (int y = screenHeight - 1; y > 0; --y) {
            for (int x = 0; x < screenWidth; ++x) {
                nextGrid[y][x] = grid[y - 1][x];
                verticalDisplacement[y][x] = std::max(verticalDisplacement[y][x] - 1, 0); // Decrease vertical displacement
            }
        }

        // Clear the top row of the next grid and reset vertical displacement
        for (int x = 0; x < screenWidth; ++x) {
            nextGrid[0][x] = ' ';
            verticalDisplacement[0][x] = 0;
        }

        // Sleep to control the speed of the rain
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}


/*
    Implemintation of the digital rain and definitions for the constructor and the start method 

    Constructor:

    The constructor initializes the DigitalRain object with the specified parameters:
        width, height: Sets the screen dimensions.
        frequency: Determines the frequency of raindrops.
        start, end: Specifies the range of ASCII values for generating random characters.
    It initializes member variables:
        screenWidth, screenHeight: Set to the provided width and height.
        raindropFrequency, asciiRangeStart, asciiRangeEnd: Set to the provided values.
        grid: Initializes the grid vector with height rows and width columns, filled with spaces.
        nextGrid: Initializes the nextGrid vector with the same size as grid, filled with spaces.
        verticalDisplacement: Initializes the verticalDisplacement vector with the same size as grid, filled with zeros.
    Additionally, it seeds the random number generator using the current time.

    Start Method:

    This method starts the digital rain effect by continuously updating the state of the screen and rendering the raindrops.
    It runs an infinite loop where each iteration represents a frame of the digital rain animation.
    Within the loop:
        It updates the nextGrid with new raindrops based on the specified frequency.
        Renders the raindrops on the screen without clearing it, allowing for the raindrops to accumulate over time.
        Swaps the grid and nextGrid.
        Moves raindrops down gradually and decreases their vertical displacement.
        Clears the top row of the nextGrid and resets the vertical displacement for the newly spawned raindrops.
        Sleeps for a short duration to control the speed of the rain animation.

    
    
    Algorithim used in digitalrain

    1. Initialization:

    The method starts with an infinite loop, representing continuous animation frames.
    In each iteration of the loop:
    The nextGrid is updated with new raindrops based on the specified frequency.
    Vertical displacement for each raindrop is reset.
    
    2. Rendering:

    The raindrops are rendered onto the screen without clearing it, allowing for accumulation over time.
    For each cell in the grid:
    If a raindrop is present (nextGrid[y][x] != ' '):
    The cursor is moved to the position (x, y + verticalDisplacement[y][x]) to ensure raindrops fall vertically.
    The raindrop character, preceded by spaces, is printed in green color using ANSI escape codes.
    The vertical displacement for the raindrop is incremented.

    3. Update:

    The grid and nextGrid are swapped, updating the raindrop positions.
    Raindrops are moved down gradually by copying them from grid to nextGrid and reducing their vertical displacement.
    The top row of nextGrid and associated vertical displacements are cleared to prepare for new raindrops.

    4. Animation Control:

    A short delay is introduced using std::this_thread::sleep_for to control the speed of the rain animation.

    
    
    Overall, this algorithm continuously updates and renders the raindrops, creating a digital rain effect where characters 
    fall from the top of the screen to the bottom, accumulating over time. The use of vertical displacement ensures that raindrops 
    fall vertically without overlapping, creating a visually appealing animation.

*/