//
//  Layer.cpp
//  Autoencoder
//
//  Created by Nick on 04/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Layer.hpp"
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

void Layer::fullyConnect(Layer &forwardLayer) {
    for (auto& origin : m_neurons) {
        for (auto& destination : forwardLayer.m_neurons) {
            origin.connectOutput(destination);
            destination.connectInput(origin);
        }
    }
}

// MARK: - Getters

Neuron Layer::getNeuron(size_t index) const {
    return m_neurons[index];
}

vector<Neuron> Layer::getNeurons() const {
    return m_neurons;
}

// MARK: - Helpers

void Layer::describe() const {
    cout << "neurons (count: " << m_neurons.size() << ")" << endl;
    for (auto neuron : m_neurons) {
        neuron.describe();
    }
}