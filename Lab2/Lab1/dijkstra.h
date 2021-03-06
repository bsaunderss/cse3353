//
//  dijkstra.h
//  Lab1
//
//  Created by Blair Saunders on 9/25/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef dijkstra_hpp
#define dijkstra_hpp

#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include "adjacencyList.h"
#include "adjacencyMatrix.h"
#include "graphData.h"


class dijkstra{
    public:

    void search(graph&, int, int);
    bool alreadyVisited (int, std::vector<int>);
    bool onPriority (int, std::vector<std::tuple<int, int, int>>);
    int spotOnPriority (int, std::vector<std::tuple<int, int, int>>);
    std::vector<int>path;
    int nodesExplored;
    graphData graphdata;

};
#endif /* dijkstra_hpp */
