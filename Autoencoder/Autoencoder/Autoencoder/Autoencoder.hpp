//
//  Autoencoder.hpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Autoencoder_hpp
#define Autoencoder_hpp

#include <stdio.h>
#include <vector>
#include "Neuron.hpp"

class Autoencoder {

public:
    Autoencoder(std::vector<int> architecture);
    
    void describe();

private:
    std::vector<Neuron> neurons;
    std::vector<Neuron> makeLayer(int layerSize);
    void fullyConnect(Neuron *origin, std::vector<Neuron> *layer);
};

#endif /* Autoencoder_hpp */
