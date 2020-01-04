//
//  Neuron.hpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Neuron_hpp
#define Neuron_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

struct NeuronHandle {
    size_t layerIndex;
    size_t neuronIndex;
    
    bool operator==(const NeuronHandle &other) const {
        return this->layerIndex == other.layerIndex && this->neuronIndex == other.neuronIndex;
    }
};

class Neuron {

public:
    // Initialisation and connections.
    Neuron(size_t layerIndex, size_t neuronIndex);
    
    // Getters.
    NeuronHandle getHandle() const;

    // Helpers.
    void describe() const;
    
private:
    NeuronHandle m_handle;
    double m_bias;
};

#endif /* Neuron_hpp */
