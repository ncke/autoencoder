//
//  NeuralNetwork.cpp
//  Autoencoder
//
//  Created by Nick on 24/04/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "NeuralNetwork.hpp"
#include <random>

// Initializer.

NeuralNetwork::NeuralNetwork(std::vector<int> layer_sizes) {

    // Load the architecture.
    int accum = 0;
    std::vector<int> n_cumulations;
    
    for (auto sz: layer_sizes) {
        n_cumulations.push_back(accum);
        accum += sz;
    }
    
    this->layer_sizes = layer_sizes;
    this->node_cumulations = n_cumulations;
    
    // Zeroise inputs and activations.
    this->inputs = std::vector<double>(accum, 0.0);
    this->activations = std::vector<double>(accum, 0.0);
    
    // Randomize connections.
    accum = 0;
    std::uniform_real_distribution<double> uniform(0.0, 1.0);
    std::default_random_engine random_engine;
    
    for (auto i = 0; i < layer_sizes.size() - 1; i++) {
        auto this_sz = layer_sizes[i];
        auto next_sz = layer_sizes[i + 1];
        auto conn_sz = this_sz * next_sz;
        
        // Every node in this layer connects to every node in the next.
        for (auto j = 0; j < conn_sz; j++) {
            double weight = uniform(random_engine);
            this->connections.push_back(weight);
        }
        
        this->conn_cumulations.push_back(accum);
        accum += conn_sz;
    }
}

// Activation.

std::vector<double> activate(std::vector<double> inputs) {
    
}

// Serialization.

int NeuralNetwork::serialize_node(int layer, int node) {
    return node_cumulations[layer] + node;
}

int NeuralNetwork::serialize_conn(int layer, int node, int dest) {
    auto base = conn_cumulations[layer];
    auto next_size = layer_sizes[layer + 1];
    return base + (next_size * node) + dest;
}
