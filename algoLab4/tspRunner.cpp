

#include "tspRunner.hpp"
#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <cstddef>
#include <sstream>
#include <chrono>
#include <thread>

//used http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/ as a reference for the time function


using namespace std::chrono;

void tspRunner:: load(std::string file){
    positions.clear();
    fr.readFile(file, positions);
}




void tspRunner::execute (){//[Executes the search algorithm]
    Graph *g = new Graph(); 
    g->createGraph(positions);
    g->createGraph();
    
    if(name == "dp"){
        dynamic(*g);
    }
    
    if(name == "brute"){
        brute(*g);
    }
    
    if(name == "genetic"){
        geneticAlgo(*g);
    }
    
    if(name == "tabu"){
        tabuAlgo(*g);
    }
    
}




void tspRunner:: select(string & algoName){
    name = algoName;
}





void tspRunner::dynamic(Graph & g){
    trav = new dp();
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    smallestPathSize = trav->run(g);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t2 - t1);
    cout<<"Time executing: "<<time.count()<<endl<<endl;
}


void tspRunner::brute(Graph & g){
    trav = new bruteForce();
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    smallestPathSize = trav->run(g);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t2 - t1);
    cout<<"Time executing: "<<time.count()<<endl<<endl;
}

void tspRunner::geneticAlgo(Graph & g){
    trav = new genetic();
    g.setSmallestPathSize(smallestPathSize);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int temp = trav->run(g);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t2 - t1);
    cout<<"Time executing: "<<time.count()<<endl<<endl;
}

void tspRunner::tabuAlgo(Graph & g){
    trav = new tabu();
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int temp = trav->run(g);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t2 - t1);
    cout<<"Time executing: "<<time.count()<<endl<<endl;
}









