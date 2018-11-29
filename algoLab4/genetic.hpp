//
//  genetic.hpp
//  algoLab3
//
//  Created by Blair Saunders on 11/27/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef genetic_hpp
#define genetic_hpp

#include <stdio.h>
#include "TSP.hpp"
class genetic: public TSP
{
public:
    int run(Graph & );
private:
    vector<int> tsp(int, vector<vector<float>>& );
    vector<vector<float>> setUp(int, vector<vector<float>>&);
    vector<pair<int, vector<int>>> randomRoutes;
    vector<pair<int, vector<int>>> childRoutes;
    int myrandom (int);
    bool alreadyIn (vector<int>, int);
    int tsp (Graph &);
    int goal;
    void setGoal(int);
    int nodeCount;
    int loop;
    void offspring (int, int, Graph &);
    void mutate(Graph & );
};

#endif /* genetic_hpp */
