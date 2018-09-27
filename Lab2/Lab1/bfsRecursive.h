//
//  bfsRecursive.h
//  Lab1
//
//  Created by Blair Saunders on 9/26/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef bfsRecursive_hpp
#define bfsRecursive_hpp
#include "adjacencyList.h"
#include "adjacencyMatrix.h"
#include <vector>
#include <stack>
#include <stdio.h>
#include "graph.h"

class bfsRecursive{
    public:
    //just change adjacencyMatrix to adjacencyList and it works
    //void search(adjacencyMatrix, int, int);


    void search(graph&, int, int, int);
    void search(graph&, int, int);

    bool alreadyVisited (int, std::vector<int>);
    bool destFound = false;
    bool done = false;
    int counter;
    std::vector<int>children;
    std::vector<int>visited;
    std::vector<std::pair<int,int>> parent_and_child;
    std::vector<int>path;
    int nodesExplored;

    int source;
    int totalNodes;

    //int parent;
    //int visiting = 0;
};
#endif /* bfsRecursive_hpp */
