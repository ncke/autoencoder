//
//  Connections.hpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Connections_hpp
#define Connections_hpp

#include "NeuronHandle.hpp"
#include <vector>

class Neuron;

struct Connection {
    NeuronHandle handle;
    double weight;
    
    Connection(const Neuron& otherNeuron);
};

class Connections {
    
public:
    // Making connections.
    void connectInput(const Neuron& otherNeuron);
    const std::vector<Connection> getInputConnections() const;
    
    // Helpers.
    void describe() const;
    
private:
    std::vector<Connection> m_inputs;

    const Connection* find(const NeuronHandle& neuronHandle) const;
    bool exists(const Connection& connection) const;
};

#endif /* Connections_hpp */
