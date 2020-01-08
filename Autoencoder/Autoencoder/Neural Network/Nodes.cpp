//
//  Nodes.cpp
//  Autoencoder
//
//  Created by Nick on 07/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Nodes.hpp"
#include "Randomization.hpp"
#include <math.h>

Nodes::Nodes(Architecture architecture) {
    
    // Create the layers of nodes.
    size_t index = 0;
    
    for (auto layerSize : architecture.layerSizes) {
        std::vector<size_t> layer;
        
        // Note: an additional node is added for the bias.
        for (auto i{ 0 }; i < (layerSize + 1); ++i) {
            m_nodes.emplace_back();
            layer.emplace_back(index++);
        }
        
        m_layers.push_back(layer);
    }
    
    // Fully connect the layers.
    for (auto layerIdx{ 1 }; layerIdx < m_layers.size(); ++layerIdx) {
        auto origLayer = m_layers[layerIdx - 1];
        auto destLayer = m_layers[layerIdx];
        
        for (auto i : origLayer)
            for (auto j : destLayer)
                connect(i, j);
    }
    
}

void Nodes::connect(size_t origin, size_t destination) {
    
    // Add the outbound connection from the origin.
    Connection outbound = Connection{ destination };
    m_nodes[origin].outputs.push_back(outbound);
    // Mirror as an inbound connection into the destination.
    Connection inbound = Connection{ origin, outbound.weight };
    m_nodes[destination].inputs.push_back(inbound);
}

std::vector<double> Nodes::activate(std::vector<double> inputs) {
    
    // Load the inputs into the input layer.
    std::vector<size_t> inputIdxs = m_layers[0];
    for (auto i{ 0 }; i < inputIdxs.size(); ++i) {
        m_nodes[inputIdxs[i]].output = inputs[i];
    }
    
    // Propagate forwards through each of the remaining layers.
    for (auto lyrIdx{ 1 }; lyrIdx < m_layers.size(); ++lyrIdx) {
        for (auto nodeIdx : m_layers[lyrIdx]) {
            computeInput(m_nodes[nodeIdx]);
            computeOutput(m_nodes[nodeIdx]);
        }
    }
    
    // Gather outputs from final layer.
    std::vector<size_t> outputIdxs = m_layers[m_layers.size()-1];
    std::vector<double> outputs;
    
    // Note: ignores the first (bias) node.
    for (auto i{ 1 }; i < outputIdxs.size(); ++i) {
        outputs.emplace_back(m_nodes[outputIdxs[i]].output);
    }
    
    return outputs;
}

void Nodes::computeInput(Node& node) {
    double input = 0.0;
    for (auto connection : node.inputs) {
        input += (m_nodes[connection.index].output * connection.weight);
    }
    node.input = input;
}

inline double sigmoid(double x) {
    double ex = exp(x);
    return ex / (1.0 + ex);
}

void Nodes::computeOutput(Node& node) {
    node.output = sigmoid(node.input);
}
