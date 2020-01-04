//
//  Neuron.cpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Neuron.hpp"
#include "Randomization.hpp"
#include <iostream>

using namespace std;

// MARK: - Life Cycle

Neuron::Neuron(size_t layerIndex, size_t neuronIndex) :
    m_bias{ randomization(-1.0, 1.0) },
    m_handle{ layerIndex, neuronIndex } {}

NeuronHandle Neuron::getHandle() const {
    return m_handle;
}

// MARK: - Helpers

void Neuron::describe() const {
    cout << "neuron: handle(" << m_handle.layerIndex << "," << m_handle.neuronIndex << "), ";
    cout << "bias: " << m_bias <<  endl;
}
