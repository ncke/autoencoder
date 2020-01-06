//
//  NeuralNetwork.cpp
//  Autoencoder
//
//  Created by Nick on 05/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "NeuralNetwork.hpp"
#include "Randomization.hpp"

size_t Architecture::getNodeCount() {
    size_t count{ 0 };
    for (auto layerSize : layerSizes) {
        count += layerSize;
    }
    return count;
}

NeuralNetwork::NeuralNetwork(Architecture architecture) :
    m_connections{ architecture.getNodeCount() } {
    
    // Create nodes in layers.
    size_t index{ 0 };
    
    for (auto layerSize : architecture.layerSizes) {
        Layer layer = Layer{};
        
        for (auto i{ 0 }; i < layerSize; ++i) {
            m_nodes.emplace_back(Node{});
            layer.addIndex(index++);
        }
        
        m_layers.emplace_back(layer);
    }
    
    // Fully connect the layers.
    for (auto i{ 1 }; i < m_layers.size(); ++i) {
        
        for (auto destIndex : m_layers[i].getIndices()) {
            for (auto origIndex : m_layers[i - 1].getIndices()) {
                
                double weight = randomization(-1.0, 1.0);
                m_connections.connect(origIndex, destIndex, weight);
            }
        }
    }
}

const std::vector<double> NeuralNetwork::activate(const std::vector<double>& inputs) {
    loadInputs(inputs);
    
    for (auto i{ 1 }; i < m_layers.size(); ++i) {
        activateLayer(m_layers[i]);
    }
    
    return getOutputs();
}

void NeuralNetwork::loadInputs(const std::vector<double>& inputs) {
    m_layers[0].loadInputs(inputs, m_nodes);
}

void NeuralNetwork::activateLayer(const Layer& layer) {
    for (auto j : layer.getIndices()) {
        
        double total = 0.0;
        for (auto& inCon : m_connections.incoming(j)) {
            total += (m_nodes[inCon.index].getOutput() * inCon.weight);
        }
        
        m_nodes[j].setInput(total);
        m_nodes[j].activate();
    }
}

const std::vector<double> NeuralNetwork::getOutputs() const {
    return m_layers[m_layers.size()-1].getOutputs(m_nodes);
}
