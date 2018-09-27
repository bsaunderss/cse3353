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

   //
   //




    string l= "list";
    string m = "matrix";


//////////////////

    int v1 = rand() % 16 + 1;
    int v2 = rand() % 16 + 1;
        cout<<algoNames[0]<<endl;





            search->selectStructure(l);
            search->select(algoNames[0]);
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();






         /*

            search->selectStructure(l);
            search->select(algoNames[0]);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();







            search->selectStructure(m);
            search->select(algoNames[0]);
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();






            search->selectStructure(m);
            search->select(algoNames[0]);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();

    //////////////////////////////

        cout<<algoNames[1]<<endl;




            search->selectStructure(l);
            search->select(algoNames[1]);
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();






            search->selectStructure(l);
            search->select(algoNames[1]);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();







            search->selectStructure(m);
            search->select(algoNames[1]);
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();






            search->selectStructure(m);
            search->select(algoNames[1]);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();


        ////////////////////
cout<<algoNames[2]<<endl;




            search->selectStructure(l);
            search->select(algoNames[2]);
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();






            search->selectStructure(l);
            search->select(algoNames[2]);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();







            search->selectStructure(m);
            search->select(algoNames[2]);
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();






            search->selectStructure(m);
            search->select(algoNames[2]);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();

        /////////////////////////////

cout<<algoNames[3]<<endl;




            search->selectStructure(l);
            search->select(algoNames[3]);
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();






            search->selectStructure(l);
            search->select(algoNames[3]);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();







            search->selectStructure(m);
            search->select(algoNames[3]);
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();






            search->selectStructure(m);
            search->select(algoNames[3]);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();

        /////////

cout<<algoNames[4]<<endl;




            search->selectStructure(l);
            search->select(algoNames[4]);
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();






            search->selectStructure(l);
            search->select(algoNames[4]);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();







            search->selectStructure(m);
            search->select(algoNames[4]);
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();






            search->selectStructure(m);
            search->select(algoNames[4]);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();

        ////////////////////////

cout<<algoNames[5]<<endl;




            search->selectStructure(l);
            search->select(algoNames[5]);
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();






            search->selectStructure(l);
            search->select(algoNames[5]);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();







            search->selectStructure(m);
            search->select(algoNames[5]);
            search->setSourceAndDest(v1, v2);
            search->execute();
            search->stats();






            search->selectStructure(m);
            search->select(algoNames[5]);
            search->setSourceAndDest(v2, v1);
            search->execute();
            search->stats();

   */







}












