//
//  Nodes.hpp
//  Autoencoder
//
//  Created by Nick on 07/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Nodes_hpp
#define Nodes_hpp

#include "Architecture.hpp"
#include "Randomization.hpp"
#include <vector>

struct Connection {
    size_t index;
    double weight;
    
    Connection(size_t index) : index{index}, weight{randomization(-1.0,1.0)} {};
    Connection(size_t index, double weight) : index{index}, weight{weight} {};
};

struct Node {
    double input;
    double output;
    std::vector<Connection> inputs;
    std::vector<Connection> outputs;
};

class Nodes {

public:
    Nodes(Architecture architecture);
    std::vector<double> activate(std::vector<double> inputs);
    
    void describe();
    
private:
    std::vector<Node> m_nodes;
    std::vector<std::vector<size_t>> m_layers;
    void connect(size_t origin, size_t destination);
    void connectBias(size_t destination);
    void computeInput(Node& node);
    void computeOutput(Node& node);
};

#endif /* Nodes_hpp */
