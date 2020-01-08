//
//  Architecture.hpp
//  Autoencoder
//
//  Created by Nick on 07/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Architecture_hpp
#define Architecture_hpp

#include <vector>

struct Architecture {
    std::vector<int> layerSizes;
    
    size_t nodeCount() const {
        size_t total = 0;
        for (auto count : layerSizes) { total += count; }
        return total;
    }
};

#endif /* Architecture_hpp */
