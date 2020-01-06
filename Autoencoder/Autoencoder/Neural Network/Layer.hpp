//
//  Layer.hpp
//  Autoencoder
//
//  Created by Nick on 05/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Layer_hpp
#define Layer_hpp

#include "Node.hpp"
#include <vector>

class Layer {
    
public:
    void addIndex(size_t index);
    const std::vector<size_t>& getIndices() const;
    
    void loadInputs(const std::vector<double>& inputs, std::vector<Node>& nodes) const;
    const std::vector<double> getOutputs(const std::vector<Node>& nodes) const;
    
private:
    std::vector<size_t> m_indices;
};

#endif /* Layer_hpp */
