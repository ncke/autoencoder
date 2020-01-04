#pragma once

#include <random>


/*inline double random(double min, double max) {
    static std::default_random_engine generator;// = std::default_random_engine();
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(generator);
}*/

class Randomization;
extern Randomization randomGenerator;
