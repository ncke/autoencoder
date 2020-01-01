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
#include <vector>

using namespace std;

Connections::Connections() {
    inputs = vector<Neuron*>();
    outputs = vector<WeightedConnection>();
}

// MARK: - Connect neurons

void Connections::connect(Neuron* origin, Neuron* destination) {
    
    // Add an outgoing connection.
    double weight = Randomization::random(-1.0, 1.0);
    WeightedConnection outgoing = { destination, weight };
    outputs.push_back(outgoing);
    
    // Add an incoming connection at the destination.
    destination->connectInput(origin);
}

void Connections::addInput(Neuron *origin) {
    inputs.push_back(origin);
}
