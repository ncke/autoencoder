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

// MARK: - Training

void Layer::loadInputs(const vector<double>& inputs) {
    for (auto i{ 0 }; i < inputs.size(); ++i) {
        m_neurons[i].setActivation(inputs[i]);
    }
}

vector<double> Layer::getInputs() const {
    vector<double> inputs;
    for (auto& neuron : m_neurons) {
        inputs.emplace_back(neuron.getTotalInput());
    }
    
    return inputs;
}

vector<double> Layer::getOutputs() const {
    vector<double> outputs;
    for (auto& neuron : m_neurons) {
        outputs.emplace_back(neuron.getActivation());
    }
    
    return outputs;
}

vector<double> Layer::computeOutputDeltas() const {
    vector<double> deltas;
    return deltas;
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
