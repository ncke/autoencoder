//
//  Connections.hpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Connections_hpp
#define Connections_hpp

#include "Neuron.hpp"
#include <vector>

struct Connection {
    NeuronHandle originHandle;
    NeuronHandle destinationHandle;
    double weight;
    
    bool operator==(const Connection &other) const {
        return this->originHandle == other.originHandle && this->destinationHandle == other.destinationHandle;
    }
};

class Connections {
    
public:
    void connectInput(const Neuron& input);
    void connectOutput(const Neuron& origin, const Neuron& destination);
    
    // Helpers.
    void describe() const;
    
private:
    std::vector<NeuronHandle> m_inputs;
    std::vector<Connection> m_outputs;
    bool inputExists(const NeuronHandle& inputHandle) const ;
    bool outputExists(const Connection& outputConnection) const;
};

#endif /* Connections_hpp */
