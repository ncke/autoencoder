//
//  NeuralNetwork.cpp
//  Autoencoder
//
//  Created by Nick on 05/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "NeuralNetwork.hpp"
#include "Randomization.hpp"

std::vector<double> NeuralNetwork::activate(std::vector<double> inputs) {
    return m_nodes.activate(inputs);
}

void NeuralNetwork::describe() {
    m_nodes.describe();
}
