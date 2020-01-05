//
//  NeuralNetwork.hpp
//  Autoencoder
//
//  Created by Nick on 04/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef NeuralNetwork_hpp
#define NeuralNetwork_hpp

#include "Layer.hpp"
#include <vector>

class Neuron;
struct NeuronHandle;

class NeuralNetwork {
    
public:
    NeuralNetwork(const std::vector<int>& architecture);
    
    // Training.
    void train(const std::vector<double>& inputs, const std::vector<double>& ideal);
    
    // Activation.
    void activate();
    double getActivation(const NeuronHandle& handle) const;
    
    // Helpers.
    void describe() const;
    
private:
    std::vector<Layer> m_layers;
    double totalInput(Neuron& neuron) const;
    Neuron getNeuron(const NeuronHandle& handle) const;
    void loadInputs(const std::vector<double>& inputs);
    const std::vector<double> getOutputs() const;
    double computeError(const std::vector<double>& ideal, const std::vector<double>& actual) const;
};

#endif /* NeuralNetwork_hpp */
