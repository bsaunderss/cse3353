//
//  main.cpp
//  Lab1
//
//  Created by Blair Saunders on 8/26/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//


#include <iostream>
#include "bubble.h"
#include "algorithm.h"
#include "organizer.h"
#include <vector>
#include "graph.h"
#include <fstream>
#include <sstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "dfsIterative.h"
#include "dfsRecursive.h"
#include "adjacencyMatrix.h"
#include "bfsIterative.h"
#include "dijkstra.h"
#include "astar.h"
#include "bfsRecursive.h"
#include "graphData.h"
#include "test.h"



using namespace std;
int main(int argc, const char * argv[]) {

    test t;

    cout<<"Nodes, Nodes Explored, time, Distance, cost"<<endl;
    for(int i = 0; i<100; i++){
       // cout<<"RUN:"<<i+1<<endl;
        t.run();
    }


   // vector<string> files;
  /*  vector<string>algoNames;
    vector<string>structures;

    organizer*c = new organizer ();

    c->addAlgoNames(algoNames);
    c->addStructures(structures);

    algorithm * search;
    searchAlgo s;
    search = &s;

    //to change the txt files, go to the load function in searchAlgo

    search->load();

   for(int i = 0; i<structures.size(); i++){
        for(int j = 0; j<algoNames.size(); j++){
            search->selectStructure(structures[i]);
            search->select(algoNames[j]);
            search->setSourceAndDest(1, 1);
            search->execute();
            search->stats();
            search->setSourceAndDest(1, 1);
            search->execute();
            search->stats();

        }
    }

   int v1 = rand() % 16 + 1;
   int v2 = rand() % 16 + 1;
   cout<<v1<<endl;
   cout<<v2<<endl;*/

    return 0;

}
