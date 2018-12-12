//
//  particle.cpp
//  algoLab3
//
//  Created by Blair Saunders on 12/8/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include <algorithm>    // std::random_shuffle
#include "particle.hpp"


particle::particle(int highest){
    int counter = highest;
    
    currentPath.push_back(1);
    for(int i = 2; i<=highest; i++){
        currentPath.push_back(i);
    }
    currentPath.push_back(1);
    random_shuffle (currentPath.begin()+1, currentPath.end()-1);
    
    bestPath = currentPath;
    noVelocity = 0;
    

}


particle::particle(const particle & object){
    currentPath = object.currentPath;
    bestPath = object.bestPath;
    
}





