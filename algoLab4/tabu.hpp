//
//  tabu.hpp
//  algoLab3
//
//  Created by Blair Saunders on 11/8/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "dp.hpp"
#include <stdio.h>
#ifndef tabu_hpp
#define tabu_hpp
class tabu: public TSP
{
    int run(Graph &);
    void createInitial(Graph &);
    void oneNeighorSwaps(Graph &);
    void twoNeighorSwaps(Graph &);
    bool checkList(vector<int>);
    vector<vector<int>>tabuList;
    int counter;
    
    vector<int>path;
};


#endif /* tabu_hpp */
