//
//  Autoencoder.cpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Autoencoder.hpp"
#include "Neuron.hpp"
#include <iostream>

using namespace std;

// MARK: - Initialisation

Autoencoder::Autoencoder(vector<int> architecture) {
    
    // Create a fully connected feed-forward neural network.
    neurons = vector<Neuron>();
    auto predecessorBegin = neurons.end();
    auto predecessorEnd = neurons.end();
    //vector<Neuron> predecessorLayer;
    
    bool isInputLayer = true;
    
    for (auto layerSize: architecture) {
        // Make the layer.
        vector<Neuron> currentLayer = makeLayer(layerSize);
        
        // Move the layer of neurons into the vector.
        predecessorBegin = neurons.end();
        
        neurons.insert(
            neurons.end(),
            currentLayer.begin(),
            currentLayer.end()
        );
        
        predecessorEnd = neurons.end();
        
        if (isInputLayer) {
            // The input layer does not have any predecessors.
            isInputLayer = false;
            continue;
        }
        
        // Otherwise fully connect every neuron in the predecessor
        // layer to every neuron in the current layer.
        
        for (auto origin = predecessorBegin; origin != predecessorEnd; origin++) {
            fullyConnect(&(*origin), &currentLayer);
            (*origin).describe();
        }
    }
    
}

vector<Neuron> Autoencoder::makeLayer(int layerSize) {
    
    vector<Neuron> layer = vector<Neuron>();
    
    for (auto i = 0; i < layerSize; i++) {
        Neuron neuron = Neuron();
        layer.push_back(neuron);
    }
    
    return layer;
}

void Autoencoder::fullyConnect(Neuron *origin, vector<Neuron> *layer) {
    cout << "origin " << origin << endl;
    
    for (auto &destination: *layer) {
        origin->connectOutput(&destination);
        destination.connectInput(origin);
    }
}

// MARK: - Helpers

void Autoencoder::describe() {
    cout << "autoencoder " << this << endl;
    cout << "total neuron count: " << neurons.size() << endl;
    
    for (auto &neuron: neurons) {
        neuron.describe();
    }
}
