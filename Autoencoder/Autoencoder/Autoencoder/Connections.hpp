//
//  Connections.hpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Connections_hpp
#define Connections_hpp

#include <stdio.h>
#include <vector>

class Neuron;

struct WeightedConnection {
    Neuron *destination;
    double weight;
};

class Connections {

public:
    Connections();
    void connect(Neuron* origin, Neuron* destination);
    void addInput(Neuron* origin);
    
private:
    std::vector<Neuron*> inputs;
    std::vector<WeightedConnection> outputs;
};

#endif /* Connections_hpp */
