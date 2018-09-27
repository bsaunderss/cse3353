//
//  dfsRecursive.h
//  Lab1
//
//  Created by Blair Saunders on 9/25/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef dfsRecursive_hpp
#define dfsRecursive_hpp
#include "adjacencyList.h"
#include "adjacencyMatrix.h"
#include <vector>
#include <stack>
#include <stdio.h>

class dfsRecursive{
    public:
    void search(graph&, int, int);
    bool alreadyVisited (int);
    std::vector<int>visited;
    std::stack<int>path_stack;
    void printV();
    bool destFound = false;
    bool done = false;
    bool go = true;
    int nodesExplored = 0;

};

#endif /* dfsRecursive_hpp */
