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


using namespace std;
class AlgoRunner{
public:
    AlgoRunner();
    void go();
private:
    void readInPositions(Graph &);
    TSP * trav;
    void dynamic(Graph &);
    void brute(Graph &);
    std::chrono::duration<double> time;//how quickly it executes
};
#endif /* AlgoRunner_hpp */
