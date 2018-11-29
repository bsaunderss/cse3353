#ifndef TSP_hpp
#define TSP_hpp
#include <stdio.h>
#include "Graph.hpp"
#include <iostream>

using namespace std;

class TSP
{
public:
    virtual int run(Graph &) = 0; // Abstract class because of this pure virtual function
};

#endif /* TSP_hpp */
