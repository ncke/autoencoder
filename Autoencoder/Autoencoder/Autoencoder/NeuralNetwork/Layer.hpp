//
//  Layer.hpp
//  Autoencoder
//
//  Created by Nick on 04/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Layer_hpp
#define Layer_hpp

#include "Connections.hpp"
#include "Neuron.hpp"
#include <vector>

class NeuralNetwork;

class Layer {
    
public:
    Layer(size_t layerIndex, size_t neuronCount);
    
    // Connection.
    void fullyConnect(Layer &forwardLayer);
    
    // Training.
    void loadInputs(const std::vector<double>& inputs);
    std::vector<double> getInputs() const;
    std::vector<double> getOutputs() const;
    std::vector<double> computeOutputDeltas() const;
    
    // Activation.
    void activate(NeuralNetwork& neuralNetwork);
    
    // Getters.
    Neuron getNeuron(size_t index) const;
    
    // Helpers.
    void describe() const;
    
private:
    std::vector<Neuron> m_neurons;
};

#endif /* Layer_hpp */
