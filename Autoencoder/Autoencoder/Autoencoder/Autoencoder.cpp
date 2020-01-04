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

Autoencoder::Autoencoder(const vector<int>& architecture) {
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

// MARK: - Helpers

void Autoencoder::describe() const {
    cout << "autoencoder " << this << endl;
    cout << "total layer count: " << m_layers.size() << endl;
    
    for (auto i{ 0 }; i < m_layers.size(); ++i) {
        cout << endl;
        cout << "layer " << i << endl;
        m_layers[i].describe();
    }
}
