//
//  Layer.cpp
//  Autoencoder
//
//  Created by Nick on 05/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Layer.hpp"

void Layer::addIndex(size_t index) {
    m_indices.emplace_back(index);
}

const std::vector<size_t>& Layer::getIndices() const {
    return m_indices;
}

void Layer::loadInputs(const std::vector<double>& inputs, std::vector<Node>& nodes) const {
    for (auto i{ 0 }; i < m_indices.size(); ++i) {
        nodes[m_indices[i]].setOutput(inputs[i]);
    }
}

const std::vector<double> Layer::getOutputs(const std::vector<Node>& nodes) const {
    std::vector<double> outputs;
    for (auto i{ 0 }; i < m_indices.size(); ++i) {
        outputs.emplace_back(nodes[m_indices[i]].getOutput());
    }
        
    return outputs;
}
