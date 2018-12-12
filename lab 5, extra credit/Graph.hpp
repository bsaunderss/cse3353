#ifndef Graph_hpp
#define Graph_hpp
#include <vector>
#include <iostream>
#include <stdio.h>
#include <utility>

using namespace std;
class Graph{
public:
    
    int smallest;
    int size;
    vector<tuple<int, float, float, float>> positions;
    vector<vector<float>> matrix;
    
    Graph();
    void createGraph(vector<tuple<int, float, float, float>>&);
    void createGraph();
    void addToPositions (int, float, float, float);
    void setSmallestPathSize (int);
    float getDistance (int, int);
    float getPathDistance(vector<int>);
   
};
#endif /* Graph_hpp */
