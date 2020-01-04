//
//  Layer.hpp
//  Autoencoder
//
//  Created by Nick on 04/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Layer_hpp
#define Layer_hpp

#include "Connections.hpp"
#include "Neuron.hpp"
#include <vector>

class Layer {
    
public:
    Layer(size_t layerIndex, size_t neuronCount);
    
    // Connection.
    void fullyConnect(Layer &forwardLayer);
    
    // Activation.
    void activate();
    
    // Helpers.
    void describe() const;
    
private:
    std::vector<Neuron> m_neurons;
};

#endif /* Layer_hpp */
