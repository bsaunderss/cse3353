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
    
    vector<string> files = {"4-nodes.txt", "10-nodes.txt"};
    vector<string>algoNames = {"dp", "brute", "gentic", "tabu"};
    tspRunner tsp;
    for(int i = 0; i<files.size(); i++){
        for (int j = 0; j<algoNames.size(); j++){
            tsp.select(algoNames[j]);
            tsp.load(files[i]);
            tsp.execute();
        }
    }
    
    return 0;
    
}
