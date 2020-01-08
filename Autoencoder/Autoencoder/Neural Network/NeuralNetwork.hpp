//
//  NeuralNetwork.hpp
//  Autoencoder
//
//  Created by Nick on 05/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef NeuralNetwork_hpp
#define NeuralNetwork_hpp

#include "Architecture.hpp"
#include "Nodes.hpp"

class NeuralNetwork {
    
public:
    NeuralNetwork(Architecture architecture) : m_nodes{architecture} {};

private:
    Nodes m_nodes;
};

#endif /* NeuralNetwork_hpp */
