//
//  Connections.cpp
//  Autoencoder
//
//  Created by Nick on 05/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Connections.hpp"

Connections::Connections(size_t nodeCount) {
    for (auto i{ 0 }; i < nodeCount; ++i) {
        m_incoming.emplace_back(std::vector<Connection>{});
        m_outgoing.emplace_back(std::vector<Connection>{});
    }
}

void Connections::connect(size_t origin, size_t destination, double weight) {
    Connection outgoing = Connection{ destination, weight };
    m_outgoing[origin].emplace_back(outgoing);
    
    Connection incoming = Connection{ origin, weight };
    m_incoming[destination].emplace_back(incoming);
}

const std::vector<Connection>& Connections::incoming(size_t index) const {
    return m_incoming[index];
}

const std::vector<Connection>& Connections::outgoing(size_t index) const {
    return m_outgoing[index];
}
