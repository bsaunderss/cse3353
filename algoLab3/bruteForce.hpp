#ifndef bruteForce_hpp
#define bruteForce_hpp
#include "TSP.hpp"
#include <stdio.h>

class bruteForce: public TSP
{
public:
    void run(Graph &);
private:
    void setBestPath();
    void addToSolutions(vector<int>, Graph & g);
    vector<pair<float,vector<int>>> solutions;
};
#endif /* bruteForce_hpp */
