//
//  Connections.cpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Connections.hpp"
#include "Neuron.hpp"
#include "Randomization.hpp"
#include <iostream>
#include <vector>

using namespace std;

// MARK: - Connect neurons

void Connections::connectInput(const Neuron& input) {
    NeuronHandle inputHandle = input.getHandle();
    
    if (!inputExists(inputHandle)) {
        m_inputs.emplace_back(inputHandle);
    }
}

void Connections::connectOutput(const Neuron& origin, const Neuron& destination) {
    // Create the connection.
    Connection connection{
        origin.getHandle(),
        destination.getHandle(),
        randomization(-1.0, 1.0) };
    
    if (!outputExists(connection)) {
        m_outputs.emplace_back(connection);
    }
}

// MARK: - Connection Uniquing

bool Connections::inputExists(const NeuronHandle& inputHandle) const {
    for (auto existingHandle : m_inputs) {
        if (inputHandle == existingHandle) {
            return true;
        }
    }
    
    return false;
}

bool Connections::outputExists(const Connection& outputConnection) const {
    for (auto existingConnection : m_outputs) {
        if (outputConnection == existingConnection) {
            return true;
        }
    }
    
    return false;
}

// MARK: - Helpers

void Connections::describe() const {
    cout << "input connections (count: " << m_inputs.size() << ")" << endl;
    for (auto handle: m_inputs) {
        cout << "input: "
             << "(" << handle.layerIndex
             << "," << handle.neuronIndex << ")" << endl;
    }
    
    cout << "output connections (count: " << m_outputs.size() << ")" << endl;
    for (auto connection: m_outputs) {
        cout << "connection: "
             << "(" << connection.originHandle.layerIndex
             << "," << connection.originHandle.neuronIndex << ")"
             << " --> "
             << "(" << connection.destinationHandle.layerIndex
             << "," << connection.destinationHandle.neuronIndex << "), "
             << "weight: " << connection.weight
             << endl;
    }
}
