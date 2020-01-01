//
//  main.cpp
//  Autoencoder
//
//  Created by Nick on 01/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Autoencoder.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // Simple autoencoder.
    vector<int> architecture = { 10, 5, 10 };
    Autoencoder autoencoder = Autoencoder(architecture);
    
    
}
