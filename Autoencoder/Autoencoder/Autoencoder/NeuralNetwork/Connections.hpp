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
    Connection(const Neuron& otherNeuron);
    
    bool operator==(const Connection &other) const {
        return this->handle == other.handle;
    }
};

struct WeightedConnection : Connection {
    double weight;
    WeightedConnection(const Neuron& otherNeuron);
};

class Connections {
    
public:
    // Making connections.
    void connectInput(const Neuron& otherNeuron);
    void connectOutput(const Neuron& otherNeuron);
    
    // Helpers.
    void describe() const;
    
private:
    std::vector<Connection> m_inputs;
    std::vector<WeightedConnection> m_outputs;
    bool exists(const Connection& connection, const std::vector<Connection>connections) const;
    bool exists(const Connection& connection, const std::vector<WeightedConnection>connections) const;
};

#endif /* Connections_hpp */
