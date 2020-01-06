//
//  Autoencoder.cpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include "Autoencoder.hpp"
#include <iostream>

using namespace std;

// MARK: - Initialisation

Autoencoder::Autoencoder(Architecture architecture) : m_network{ architecture } {}
