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

// MARK: - Connection Structure

Connection::Connection(const Neuron& otherNeuron) :
    handle{ otherNeuron.getHandle() },
    weight{ randomization(-1.0, 1.0) } {}

// MARK: - Connecting neurons

void Connections::connectInput(const Neuron& otherNeuron) {
    Connection connection{ otherNeuron };
    
    if (!exists(connection)) {
        m_inputs.emplace_back(connection);
    }
}

// MARK: - Connection Management

const vector<Connection> Connections::getInputConnections() const {
    return m_inputs;
}

const Connection* Connections::find(const NeuronHandle& neuronHandle) const {
    for (auto& existingConnection : m_inputs) {
        if (neuronHandle == existingConnection.handle) {
            return &existingConnection;
        }
    }
    
    return nullptr;
}

bool Connections::exists(const Connection& connection) const {
    return find(connection.handle) != nullptr;
}

// MARK: - Helpers

void Connections::describe() const {
    cout << "input connections (count: " << m_inputs.size() << ")" << endl;
    for (auto connection: m_inputs) {
        cout << "input: "
             << "(" << connection.handle.layerIndex
             << "," << connection.handle.neuronIndex << ") "
             << "weight: " << connection.weight
             << endl;
    }
}
