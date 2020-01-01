//
//  Neuron.hpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Neuron_hpp
#define Neuron_hpp

#include <stdio.h>
#include <vector>
#include "Connections.hpp"

class Neuron {

public:
    Neuron();
    void connectInput(Neuron *origin);
    void connectOutput(Neuron *destination);
    
private:
    Connections connections;
};

#endif /* Neuron_hpp */
