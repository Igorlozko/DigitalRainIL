#pragma once
#ifndef DIGITALRAIN_H
#define DIGITALRAIN_H

#include <vector>
#include "Raindrop.h"

class DigitalRain {
public:
    DigitalRain();
    void start();

private:
    std::vector<Raindrop> raindrops;
};

#endif // DIGITALRAIN_H