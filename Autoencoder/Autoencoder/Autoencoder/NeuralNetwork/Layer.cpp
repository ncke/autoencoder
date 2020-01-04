//
//  Layer.cpp
//  Autoencoder
//
//  Created by Nick on 04/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Layer.hpp"
#include "NeuralNetwork.hpp"
#include "Neuron.hpp"
#include <iostream>
#include <vector>

using namespace std;

Layer::Layer(size_t layerIndex, size_t neuronCount) {
    for (size_t i{ 0 }; i < neuronCount; ++i) {
        m_neurons.emplace_back(Neuron{ layerIndex, i });
    }
}

// MARK: - Connection

void Layer::fullyConnect(Layer& forwardLayer) {
    for (auto& origin : m_neurons) {
        for (auto& destination : forwardLayer.m_neurons) {
            destination.connectInput(origin);
        }
    }
}

// MARK: - Activation

void Layer::activate(NeuralNetwork& neuralNetwork) {
    // Activate each neuron.
    for (auto& neuron : m_neurons) {
        neuron.activate(neuralNetwork);
    }
}

// MARK: - Getters

Neuron Layer::getNeuron(size_t index) const {
    return m_neurons[index];
}

// MARK: - Helpers

void Layer::describe() const {
    cout << "has " << m_neurons.size() << " neurons" << endl;
    for (auto neuron : m_neurons) {
        neuron.describe();
    }
}
