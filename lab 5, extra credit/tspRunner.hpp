//
//  tspAlgo.hpp
//  algoLab3
//
//  Created by Blair Saunders on 11/30/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef tspAlgo_hpp
#define tspAlgo_hpp
#include <stdio.h>
#include "tabu.hpp"
#include "genetic.hpp"
#include "dp.hpp"
#include "sa.hpp"
#include "pso.hpp"
#include "bruteForce.hpp"
#include "TSP.hpp"
#include "fileReader.hpp"
#include "Graph.hpp"


//using namespace std;
class tspRunner {
public:
    void load(string);
    void execute (); //[Executes the algorithm]
    void select(string &);
    string name;//algoName
    std::chrono::duration<double> time;//how quickly it executes
    std::vector<std::tuple<int, float, float, float>> positions;
    
    void excuteAlgo(Graph & , TSP *);
    TSP * trav;
    bool setSmallest;
    void testing();
    int temp;
    
    int smallestPathSize;
    
    fileReader fr;
    
    
};
#endif /* tspAlgo_hpp */
