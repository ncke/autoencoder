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

Connection::Connection(const Neuron& otherNeuron) : handle{ otherNeuron.getHandle() } {}

WeightedConnection::WeightedConnection(const Neuron& otherNeuron) :
    Connection(otherNeuron), weight{ randomization(-1.0, 1.0) } {}

// MARK: - Connect neurons

void Connections::connectInput(const Neuron& otherNeuron) {
    Connection connection{ otherNeuron };
    
    if (!exists(connection, m_inputs)) {
        m_inputs.emplace_back(connection);
    }
}

void Connections::connectOutput(const Neuron& otherNeuron) {
    // Create the connection.
    WeightedConnection connection{ otherNeuron };
    
    if (!exists(connection, m_outputs)) {
        m_outputs.emplace_back(connection);
    }
}

// MARK: - Connection Uniquing

bool Connections::exists(const Connection& connection, const std::vector<Connection>connections) const {
    for (auto existingConnection : connections) {
        if (connection == existingConnection) {
            return true;
        }
    }
    
    return false;
}

bool Connections::exists(const Connection& connection, const std::vector<WeightedConnection>connections) const {
    for (auto existingConnection : connections) {
        if (connection == existingConnection) {
            return true;
        }
    }
    
    return false;
}

// MARK: - Helpers

void Connections::describe() const {
    cout << "input connections (count: " << m_inputs.size() << ")" << endl;
    for (auto connection: m_inputs) {
        cout << "input: "
             << "(" << connection.handle.layerIndex
             << "," << connection.handle.neuronIndex << ")"
             << endl;
    }
    
    cout << "output connections (count: " << m_outputs.size() << ")" << endl;
    for (auto connection: m_outputs) {
        cout << "output: "
             << "(" << connection.handle.layerIndex
             << "," << connection.handle.neuronIndex << ") "
             << "weight: " << connection.weight
             << endl;
    }
}
