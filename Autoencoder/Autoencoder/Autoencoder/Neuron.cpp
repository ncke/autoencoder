//
//  Neuron.cpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Neuron.hpp"

using namespace std;

// MARK: - Life Cycle

Neuron::Neuron() {
    // Initialise connections.
    connections = Connections();
}



// MARK: - Connections

void Neuron::connectInput(Neuron *origin) {
    connections.addInput(origin);
}

void Neuron::connectOutput(Neuron *destination) {
    connections.connect(this, destination);
}

