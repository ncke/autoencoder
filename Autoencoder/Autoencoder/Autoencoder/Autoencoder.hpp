//
//  Autoencoder.hpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Autoencoder_hpp
#define Autoencoder_hpp

#include "Layer.hpp"
#include <stdio.h>
#include <vector>

class Autoencoder {

public:
    Autoencoder(const std::vector<int>& architecture);
    
    // Helpers.
    void describe() const;

private:
    std::vector<Layer> m_layers;
};

#endif /* Autoencoder_hpp */
