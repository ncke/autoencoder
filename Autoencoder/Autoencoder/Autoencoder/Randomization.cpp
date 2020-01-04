//
//  Randomization.cpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Randomization.hpp"
#include <random>

void Randomization::setSeed(uint seed) {
    m_generator = std::default_random_engine{ seed };
}

double Randomization::random(double min, double max) {
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(m_generator);
}
