#include "test.h"
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


test::test()
{



}



void test:: run(string algoName, string algoStructure){

   // vector<string>algoNames;
   // vector<string>structures;



   /* organizer*c = new organizer ();

    c->addAlgoNames(algoNames);
    c->addStructures(structures);*/

    algorithm * search;
    searchAlgo s;
    search = &s;
    search->load();





    string l= "list";
    string m = "matrix";



    int v1 = rand() % 16 + 1;
    int v2 = rand() % 16 + 1;

            search->selectStructure(algoStructure);
            search->select(algoName);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();



}












