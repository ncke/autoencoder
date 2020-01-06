//
//  Node.cpp
//  Autoencoder
//
//  Created by Nick on 05/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Node.hpp"
#include <math.h>

void Node::activate() {
    double ex = exp(m_input);
    m_output = ex / (1.0 + ex);
}

void Node::setInput(double input) {
    m_input = input;
}

double Node::getInput() const {
    return m_input;
}

void Node::setOutput(double output) {
    m_output = output;
}

double Node::getOutput() const {
    return m_output;
}
