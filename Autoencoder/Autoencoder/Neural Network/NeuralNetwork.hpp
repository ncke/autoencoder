//
//  NeuralNetwork.hpp
//  Autoencoder
//
//  Created by Nick on 05/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef NeuralNetwork_hpp
#define NeuralNetwork_hpp

#include "Node.hpp"
#include "Layer.hpp"
#include "Connections.hpp"
#include <vector>

struct Architecture {
    std::vector<int> layerSizes;
    size_t getNodeCount();
};

class NeuralNetwork {
    
public:
    NeuralNetwork(Architecture architecture);
    
private:
    std::vector<Node> m_nodes;
    
    Connections m_connections;
    
    const std::vector<double> activate(const std::vector<double>& inputs);
    
    std::vector<Layer> m_layers;
    void loadInputs(const std::vector<double>& inputs);
    void activateLayer(const Layer& layer);
    double totalInput(const Node& node) const;
    const std::vector<double> getOutputs() const;
};

#endif /* NeuralNetwork_hpp */
