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

    
    // private:
    
    string name;//algoName
    vector<int> path;//algorithm path
    
    int nodesExplored;
    
    std::chrono::duration<double> time;//how quickly it executes
    std::vector<std::tuple<int, float, float, float>> positions;
    
    
    TSP * trav;
    void dynamic(Graph &);
    void brute(Graph &);
    void geneticAlgo(Graph &);
    void tabuAlgo(Graph &);
    
    int smallestPathSize;
    
    fileReader fr;
    
    
};
#endif /* tspAlgo_hpp */
