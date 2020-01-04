//
//  NeuralNetwork.cpp
//  Autoencoder
//
//  Created by Nick on 04/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "NeuralNetwork.hpp"
#include "Neuron.hpp"
#include "NeuronHandle.hpp"
#include <vector>

using namespace std;

// MARK: - Initialisation

NeuralNetwork::NeuralNetwork(const vector<int>& architecture) {
    // Create the layers.
    for (size_t layerIndex{ 0 }; layerIndex < architecture.size(); ++layerIndex) {
        Layer layer = Layer{ layerIndex, static_cast<size_t>(architecture[layerIndex]) };
        m_layers.emplace_back(layer);
    }
    
    // Create connections to form a fully-connected network.
    for (size_t layerIndex{ 1 }; layerIndex < architecture.size(); ++layerIndex) {
        m_layers[layerIndex - 1].fullyConnect(m_layers[layerIndex]);
    }
}

// MARK: - Activation

// MARK: - Getters

Neuron NeuralNetwork::getNeuron(NeuronHandle& handle) const {
    return m_layers[handle.layerIndex].getNeuron(handle.neuronIndex);
}

// MARK: - Helpers

void NeuralNetwork::describe() const {
    cout << "neural network " << this << endl;
    cout << "total layer count: " << m_layers.size() << endl;
    
    for (auto i{ 0 }; i < m_layers.size(); ++i) {
        cout << endl;
        cout << "layer " << i << endl;
        m_layers[i].describe();
    }
}
