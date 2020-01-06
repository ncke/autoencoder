//
//  Connections.hpp
//  Autoencoder
//
//  Created by Nick on 05/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Connections_hpp
#define Connections_hpp

#include <vector>

struct Connection {
    size_t index;
    double weight;
};

class Connections {
    
public:
    Connections(size_t nodeCount);
    void connect(size_t origin, size_t destination, double weight);
    const std::vector<Connection>& incoming(size_t index) const;
    const std::vector<Connection>& outgoing(size_t index) const;
    
private:
    std::vector<std::vector<Connection>> m_incoming;
    std::vector<std::vector<Connection>> m_outgoing;
};

#endif /* Connections_hpp */
