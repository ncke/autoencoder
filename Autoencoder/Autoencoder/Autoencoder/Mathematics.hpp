//
//  Mathematics.hpp
//  Autoencoder
//
//  Created by Nick on 04/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Mathematics_hpp
#define Mathematics_hpp

#include <math.h>

inline double sigmoid(double x) {
    double ex = exp(x);
    return ex / (1.0 + ex);
}

#endif /* Mathematics_hpp */
