//
//  main.cpp
//  Lab1
//
//  Created by Blair Saunders on 8/26/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//


#include <iostream>
#include "tspRunner.hpp" 
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>


using namespace std;


int main(int argc, const char * argv[]) {
    tspRunner tsp;
    //if you want to provide specific input
    //put the file names in the files vector
    
    vector<string> files = {"tester.txt", "10-nodes.txt"};
    
    //the program is set to run DP, SA, and PSO
    //to test specific algorithms, put the algorithm identifier in the algoNames vector
    //keys for algo identifiers:
    
    //     dynamic                     - "dp"
    //     brute force                 - "brute"
    //     genetic                     - "genetic"
    //     tabu                        - "tabu"
    //     simulated annealing         - "sa"
    //     particle swarm optimization - "pso"
    
    
//DP needs to occur before sa and pso because both use stopping points
    vector<string>algoNames = {"dp", "sa", "pso"};
    for(int i = 0; i<files.size(); i++){
        for (int j = 0; j<algoNames.size(); j++){
            tsp.select(algoNames[j]);
            tsp.load(files[i]);
            tsp.execute();
        }
    }
    
   
    //if you want to test with randomly generated x,y,x values, call this function
    //the function will test DP, SA, and PSO
    //testing conditions can be modified in the tspRunner testing fuction
   
    
    //tsp.testing();
    return 0;
    
}
