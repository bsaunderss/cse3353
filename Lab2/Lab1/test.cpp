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

void test:: run(){

    vector<string>algoNames;
    vector<string>structures;



    organizer*c = new organizer ();

    c->addAlgoNames(algoNames);
    c->addStructures(structures);

    algorithm * search;
    searchAlgo s;
    search = &s;

    //to change the txt files, go to the load function in searchAlgo

  //  vector<int> matrixTimeArray [algoNames.size()] ;
  //  vector<int> listTimeArray [algoNames.size()];

    search->load();

    int v1 = rand() % 16 + 1;
    int v2 = rand() % 16 + 1;




    string l= "list";
    string m = "matrix";



        //for(int j = 0; j<algoNames.size(); j++){
            search->selectStructure(m);
            search->select(algoNames[4]);
            //cout<<"Source to Destination"<<endl;
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();
            /*cout<<"Destination to Source"<<endl;
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();*/
      //  }


      /*  for(int j = 0; j<algoNames.size(); j++){
            search->selectStructure(m);
            search->select(algoNames[j]);
            cout<<"Source to Destination"<<endl;
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();
            cout<<"Destination to Source"<<endl;
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();
        }*/














}
