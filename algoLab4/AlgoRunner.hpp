#ifndef AlgoRunner_hpp
#define AlgoRunner_hpp
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include <ctime>
#include <locale>
#include <ratio>

#include "bruteForce.hpp"
#include "dp.hpp"
#include "genetic.hpp"
#include "tabu.hpp"


using namespace std;
class AlgoRunner{
public:
    AlgoRunner();
    void go();
    void testing();
private:
    void readInPositions(Graph &);
    TSP * trav;
    void dynamic(Graph &);
    void brute(Graph &);
    void geneticAlgo(Graph &);
    void tabuAlgo(Graph &);
    //void testing();
    
    int smallestPathSize;
    std::chrono::duration<double> time;//how quickly it executes
};
#endif /* AlgoRunner_hpp */
