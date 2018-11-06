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
    void addToNodes(int);
    float getDistance (int, int);
    float getPathDistance(vector<int>);

    int size;
    vector<int>nodes;
    vector<tuple<int, float, float, float>> positions;
    vector<vector<float>> matrix;
};
#endif /* Graph_hpp */
