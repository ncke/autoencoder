//
//  Nodes.cpp
//  Autoencoder
//
//  Created by Nick on 07/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Nodes.hpp"
#include "Randomization.hpp"
#include <iostream>
#include <math.h>

#define BIAS_ORIGIN ((size_t)(-1))

Nodes::Nodes(Architecture architecture) {
    
    // Create the layers of nodes.
    size_t index = 0;
    
    for (auto layerSize : architecture.layerSizes) {
        std::vector<size_t> layer;
        
        for (auto i{ 0 }; i < layerSize; ++i) {
            m_nodes.emplace_back();
            layer.emplace_back(index++);
        }
        
        m_layers.emplace_back(layer);
    }
    
    // Fully connect each layer.
    for (auto layerIdx{ 0 }; layerIdx < m_layers.size(); ++layerIdx) {
        
        // For each node in the layer...
        for (auto i : m_layers[layerIdx]) {
            
            // Connect forwards unless final layer.
            auto destIdx = layerIdx + 1;
            if (destIdx < m_layers.size())
                for (auto j : m_layers[destIdx])
                    connect(i, j);
                
            // Add bias connection if required.
            if (architecture.useBias)
                connectBias(i);
        }
    }
    
}

void Nodes::connect(size_t origin, size_t destination) {
    
    // Add the outbound connection from the origin.
    Connection outbound = Connection{ destination };
    m_nodes[origin].outputs.emplace_back(outbound);
    // Mirror as an inbound connection into the destination.
    Connection inbound = Connection{ origin, outbound.weight };
    m_nodes[destination].inputs.emplace_back(inbound);
}

void Nodes::connectBias(size_t destination) {
    
    // Add the inbound bias connection into the destination.
    Connection inbound = Connection{ BIAS_ORIGIN };
    m_nodes[destination].inputs.emplace_back(inbound);
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
    // Sum the weighted inputs and load into the input property.
    double input = 0.0;
    for (auto connection : node.inputs) {
        input += (m_nodes[connection.index].output * connection.weight);
    }
    node.input = input;
}

inline double sigmoid(double x) {
    // Sigmoid function: e^x / (1 + e^x)
    double ex = exp(x);
    return ex / (1.0 + ex);
}

void Nodes::computeOutput(Node& node) {
    // Apply the sigmoid function to the input property, load into
    // the output property.
    node.output = sigmoid(node.input);
}

void Nodes::describe() {
    // Describe the nodes.
    std::cout << "total nodes:  " << m_nodes.size() << std::endl;
    std::cout << "total layers: " << m_layers.size() << std::endl;
    
    for (auto i{ 0 }; i < m_layers.size(); ++i) {
        std::cout << std::endl
            << "describing layer: " << i << std::endl;
        
        for (auto j : m_layers[i]) {
            
            std::cout << std::endl
                << "describing node: " << j << " (in layer " << i << ")"
                << std::endl << std::endl;
            
            auto node = m_nodes[j];
            
            for (auto input : node.inputs) {
                if (input.index == BIAS_ORIGIN) {
                    std::cout << "input from bias, weight: " << input.weight << std::endl;
                } else {
                std::cout << "input from node: " << input.index << ", weight: " << input.weight << std::endl;
                }
            }
            
            for (auto output : node.outputs) {
                std::cout << "output to node: " << output.index << ", weight: " << output.weight << std::endl;
            }
            
            
        }
        
        
        
    }
}
