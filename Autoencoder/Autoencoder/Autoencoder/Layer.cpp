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

void Layer::fullyConnect(Layer &forwardLayer) {
    for (auto origin : m_neurons) {
        for (auto destination : forwardLayer.m_neurons) {
            m_connections.connectOutput(origin, destination);
            forwardLayer.m_connections.connectInput(origin);
        }
    }
}

// MARK: - Helpers

void Layer::describe() const {
    cout << "neurons (count: " << m_neurons.size() << ")" << endl;
    for (auto neuron : m_neurons) {
        neuron.describe();
    }
    
    m_connections.describe();
}
