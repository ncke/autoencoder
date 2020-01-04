//
//  NeuralNetwork.hpp
//  Autoencoder
//
//  Created by Nick on 04/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef NeuralNetwork_hpp
#define NeuralNetwork_hpp

#include "Layer.hpp"
#include <vector>

class NeuralNetwork {
    
public:
    NeuralNetwork(const std::vector<int>& architecture);
    
    // Helpers.
    void describe() const;
    
private:
    std::vector<Layer> m_layers;
};

#endif /* NeuralNetwork_hpp */
