//
//  NeuralNetwork.cpp
//  Autoencoder
//
//  Created by Nick on 24/04/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "NeuralNetwork.hpp"
#include <random>

NeuralNetwork::NeuralNetwork(std::vector<int> layer_sizes) {
    std::vector<double> inputs = std::vector<double>();
    std::vector<double> activations = std::vector<double>();
    std::vector<double> connections = std::vector<double>();
    
    std::uniform_real_distribution<double> uniform(0.0, 1.0);
    std::default_random_engine random_engine;
    
    for (int k = 0; k < layer_sizes.size(); k++) {
        int layer_size = layer_sizes[k];
        
        for (int i = 0; i < layer_size; i++) {
            
            // Zeroise inputs and activations.
            inputs.push_back(0.0);
            activations.push_back(0.0);
            
            // Skip making connections for the last layer.
            if (i == layer_size - 1) continue;
            
            // Make connections.
            int next_size = layer_sizes[k + 1];
            
            for (int j = 0; j < next_size; j++) {
                double weight = uniform(random_engine);
                connections.push_back(weight);
            }
        }
    }
    
    this->layer_sizes = layer_sizes;
    this->inputs = inputs;
    this->activations = activations;
    this->connections = connections;
}
