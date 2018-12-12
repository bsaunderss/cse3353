//
//  sa.hpp
//  algoLab3
//
//  Created by Blair Saunders on 12/8/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//
#include "TSP.hpp"
#ifndef sa_hpp
#define sa_hpp

#include <stdio.h>
class sa: public TSP
{
public:
    int run(Graph & );
private:
    
    float goal;
    float temperature;
    float change;
    vector<int>route;
    vector<int>nextRoute;
    float probability;
    int nodeCount;
    
    void tsp(Graph & );
    void init(Graph &);
    vector<int>getNext(Graph &);
    bool move();
    
};
#endif /* sa_hpp */
