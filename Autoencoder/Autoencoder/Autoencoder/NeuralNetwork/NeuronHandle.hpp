//
//  NeuronHandle.hpp
//  Autoencoder
//
//  Created by Nick on 04/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef NeuronHandle_hpp
#define NeuronHandle_hpp

#include <stdio.h>

struct NeuronHandle {
    size_t layerIndex;
    size_t neuronIndex;
    
    bool operator==(const NeuronHandle &other) const {
        return this->layerIndex == other.layerIndex && this->neuronIndex == other.neuronIndex;
    }
};

#endif /* NeuronHandle_hpp */
