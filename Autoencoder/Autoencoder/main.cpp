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
    
    vector<int> layerSizes = { 3, 2, 3 };
    Architecture architecture{ layerSizes };
    
    Autoencoder autoencoder = Autoencoder(architecture);
    
}
