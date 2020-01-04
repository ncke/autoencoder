//
//  Neuron.cpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Mathematics.hpp"
#include "Neuron.hpp"
#include "Randomization.hpp"
#include <iostream>

using namespace std;

// MARK: - Initializer

Neuron::Neuron(size_t layerIndex, size_t neuronIndex) :
    m_bias{ randomization(-1.0, 1.0) },
    m_handle{ layerIndex, neuronIndex } {}

// MARK: - Connection

void Neuron::connectInput(const Neuron& otherNeuron) {
    m_connections.connectInput(otherNeuron);
}

void Neuron::connectOutput(const Neuron& otherNeuron) {
    m_connections.connectOutput(otherNeuron);
}

// MARK: - Activation

void Neuron::activate(double input) {
    m_activation = sigmoid(input);
}

// MARK: - Getters

NeuronHandle Neuron::getHandle() const {
    return m_handle;
}

double Neuron::getActivation() const {
    return m_activation;
}

// MARK: - Helpers

void Neuron::describe() const {
    cout << endl;
    cout << "neuron: handle(" << m_handle.layerIndex << "," << m_handle.neuronIndex << "), ";
    cout << "bias: " << m_bias <<  endl;
    m_connections.describe();
}