//
//  Randomization.hpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Randomization_hpp
#define Randomization_hpp

#include <stdio.h>
#include <random>

class Randomization {
    
public:
    double operator ()(double min, double max) {
        return random(min, max);
    }
    
private:
    double random(double min, double max);
    std::default_random_engine generator;
};

static Randomization randomization;

#endif /* Randomization_hpp */
