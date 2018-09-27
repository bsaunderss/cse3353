//
//  searchAlgo.h
//  Lab1
//
//  Created by Blair Saunders on 9/26/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef searchAlgo_hpp
#define searchAlgo_hpp

#include <stdio.h>
#include "algorithm.h"
#include "dfsIterative.h"
#include "dfsRecursive.h"
#include "bfsIterative.h"
#include "dijkstra.h"
#include "astar.h"
#include "bfsRecursive.h"


//using namespace std;
class searchAlgo: public algorithm {
    void load (); //[Takes a filename as and can read input data file]
    void load(string);
    void selectStructure(string&);
    void execute (); //[Executes the algorithm]
    void display(); //[Prints solution to screen]
    void stats(); //[Prints algorithm name, execution time and number of records analyzed to screen in a readable format]
    void save (string); //[Saves solution to file path given as input]
    void configure ();// [Future expandability ]
    void select (string&);//[enum or int or id passed as input and loads corresponding algorithm to interface]
    void clearOutput(string);
    void setSourceAndDest(int, int);
   // private:

        string name;//algoName
        string structure;//list or matrix
        vector<int> path;//algorithm path
        std::chrono::duration<double> time;//how quickly it executes
        int nodesExplored;


        std::vector<std::pair<int,int>> spots;
        std::vector<std::tuple<int, int, int>> weights;
        std::vector<std::tuple<int, int, int, int>> positions;

        graphData graphdata;

        int start, finish;




};
#endif /* searchAlgo_hpp */
