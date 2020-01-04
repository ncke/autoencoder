//
//  Autoencoder.cpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Autoencoder.hpp"
#include "Layer.hpp"
#include <iostream>

using namespace std;

// MARK: - Initialisation

Autoencoder::Autoencoder(const vector<int>& architecture) : m_network{ architecture } {
    // Create the neural network.
    
}

// MARK: - Helpers

void Autoencoder::describe() const {
    m_network.describe();
}
