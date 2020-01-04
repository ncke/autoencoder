//
//  Neuron.hpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Neuron_hpp
#define Neuron_hpp

#include "Connections.hpp"
#include <stdio.h>
#include <vector>
#include <iostream>

class NeuralNetwork;

class Neuron {

public:
    // Initialisation and connections.
    Neuron(size_t layerIndex, size_t neuronIndex);
    
    // Connection.
    void connectInput(const Neuron& otherNeuron);
    
    // Activation.
    void activate(NeuralNetwork& neuralNetwork);
    
    // Getters.
    NeuronHandle getHandle() const;
    double getActivation() const;

    // Helpers.
    void describe() const;
    
private:
    Connections m_connections;
    NeuronHandle m_handle;
    double m_bias;
    double m_activation;
};

#endif /* Neuron_hpp */
