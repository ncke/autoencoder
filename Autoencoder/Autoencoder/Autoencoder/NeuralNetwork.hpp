//
//  NeuralNetwork.hpp
//  Autoencoder
//
//  Created by Nick on 24/04/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef NeuralNetwork_hpp
#define NeuralNetwork_hpp

#include <stdio.h>
#include <vector>

class NeuralNetwork {
    
public:
    NeuralNetwork(std::vector<int> layer_sizes);
    std::vector<double> activate(std::vector<double> inputs);
    
    ~NeuralNetwork() {}
    
private:
    std::vector<int> layer_sizes;
    std::vector<double> inputs;
    std::vector<double> activations;
    std::vector<double> connections;
};

#endif /* NeuralNetwork_hpp */
