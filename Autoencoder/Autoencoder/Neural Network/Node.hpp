//
//  Node.hpp
//  Autoencoder
//
//  Created by Nick on 05/01/2020.
//  Copyright © 2020 Nick. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

class Node {
    
public:
    void activate();
    
    void setInput(double input);
    double getInput() const;
    
    void setOutput(double output);
    double getOutput() const;
    
private:
    double m_input;
    double m_output;
};

#endif /* Node_hpp */
