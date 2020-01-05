//
//  NeuralNetwork.cpp
//  Autoencoder
//
//  Created by Nick on 04/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Mathematics.hpp"
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

// MARK: - Training

void NeuralNetwork::train(const std::vector<double>& inputs, const std::vector<double>& ideal) {
    loadInputs(inputs);
    activate();
    vector<double> outputs = getOutputs();
    double error = computeError(ideal, outputs);
    
    
    
}

void NeuralNetwork::loadInputs(const std::vector<double>& inputs) {
    m_layers[0].loadInputs(inputs);
}

const vector<double> NeuralNetwork::getOutputs() const {
    return m_layers[m_layers.size() - 1].getOutputs();
}

double NeuralNetwork::computeError(const std::vector<double>& ideal, const std::vector<double>& actual) const {
    // Sum of squares error function.
    double error = 0.0;
    
    for (auto i{ 0 }; i < ideal.size(); ++i) {
        double diff = actual[i] - ideal[i];
        error += (diff * diff);
    }
    
    return error;
}

// MARK: - Activation

void NeuralNetwork::activate() {
    // Activate each layer, except the first (input) layer.
    for (auto i{ 1 }; i < m_layers.size(); ++i) {
        m_layers[i].activate(*this);
    }
}

// MARK: - Getters

double NeuralNetwork::getActivation(const NeuronHandle& handle) const {
    return getNeuron(handle).getActivation();
}

Neuron NeuralNetwork::getNeuron(const NeuronHandle& handle) const {
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
