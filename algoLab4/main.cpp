//
//  main.cpp
//  Lab1
//
//  Created by Blair Saunders on 8/26/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//


#include <iostream>
#include "organizer.hpp"
#include "tspRunner.hpp" 
#include <vector>


#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>


using namespace std;
int main(int argc, const char * argv[]) {
    
    vector<string> files;
    vector<string>algoNames;
    
    //to control the input files that are being sorted and the sort methods being used, you go to the class 'organizer' and control it from there
    //right now the data sets with 10 values are being checked and each of the sort methods is being used. You can change this though
    
    organizer*c = new organizer ();
    c->addFilePaths(files);
    c->addAlgoNames(algoNames);
    
   // algorithm * tsp = nullptr;
    tspRunner tsp;
  //  tsp = new tspAlgo();
   // sort->clearOutput("output_file.txt");//making sure the output file is emtpy
    
    for(int i = 0; i<files.size(); i++){
        for (int j = 0; j<algoNames.size(); j++){
            tsp.select(algoNames[j]);
            tsp.load(files[i]);
            tsp.execute();
            
        }
    }
    
    return 0;
    
}
