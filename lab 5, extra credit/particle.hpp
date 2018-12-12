//
//  particle.hpp
//  algoLab3
//
//  Created by Blair Saunders on 12/8/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//
//#include <vector>
#include "Graph.hpp"
#include<math.h>
#ifndef particle_hpp
#define particle_hpp

#include <stdio.h>
#include <stdlib.h>

using namespace std;
class particle{

public:
    particle(int);
    particle(const particle &);
    float noVelocity;
    
    vector<int>bestPath;
    vector<int>currentPath;
    
};
#endif /* particle_hpp */
