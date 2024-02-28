#pragma once
#ifndef RAINDROP_H
#define RAINDROP_H

#include <string>

class Raindrop {
public:
    Raindrop(int x, int y, char symbol);
    void update();
    std::string toString() const;

private:
    int x;
    int y;
    char symbol;
};

#endif // RAINDROP_H
