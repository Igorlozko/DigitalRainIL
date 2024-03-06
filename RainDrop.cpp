#include "Raindrop.h"

Raindrop::Raindrop(int x, int y, char symbol) : x(x), y(y), symbol(symbol) {
    // Initialize Raindrop object
}

void Raindrop::update() {
    // Update raindrop position or state
}

std::string Raindrop::toString() const {
    // Convert raindrop to string representation
    return std::string(1, symbol);
}

