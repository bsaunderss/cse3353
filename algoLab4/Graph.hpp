#ifndef Graph_hpp
#define Graph_hpp
#include <vector>
#include <iostream>
#include <stdio.h>
#include <utility>

using namespace std;
class Graph{
public:
    Graph();
    void createGraph();
    void addToPositions (int, float, float, float);
    float getDistance (int, int);
    float getPathDistance(vector<int>);
    int smallest;
    int size;
    vector<tuple<int, float, float, float>> positions;
    vector<vector<float>> matrix;
    void setSmallestPathSize (int);
};
#endif /* Graph_hpp */
