//
//  pso.hpp
//  algoLab3
//
//  Created by Blair Saunders on 12/8/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef pso_hpp
#define pso_hpp
#include "TSP.hpp"
#include "particle.hpp"
#include <stdio.h>
class pso: public TSP
{
public:
    int run(Graph & );
private:
    
     float goal;
     int nodeCount;
     vector<int>globalBest;
     vector<particle> particleVector;
    int counter;
    void print(vector<int>);
    void move (particle &, Graph &);   
    void longestLink(vector<int>&, Graph & g);
    void init(Graph & );
    
};
#endif /* pso_hpp */
