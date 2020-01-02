//
//  Neuron.cpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Neuron.hpp"
#include "Randomization.hpp"
#include <iostream>

using namespace std;

// MARK: - Life Cycle

Neuron::Neuron() {
    // Initialise connections and randomize bias.
    connections = Connections();
    bias = Randomization::random(-1.0, 1.0);
}

// MARK: - Connections

void Neuron::connectInput(Neuron *origin) {
    connections.addInput(origin);
}

void Neuron::connectOutput(Neuron *destination) {
    connections.connect(this, destination);
}

// MARK: - Helpers

void Neuron::describe() {
    cout << "------------------- neuron at " << this << endl;
    cout << "bias: " << bias << endl;
    connections.describe();
}
