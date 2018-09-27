//
//  bfs.h
//  Lab1
//
//  Created by Blair Saunders on 9/25/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef bfs_hpp
#define bfs_hpp

#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include "adjacencyList.h"
#include "adjacencyMatrix.h"

class bfsIterative{
    public:
    //just change adjacencyMatrix to adjacencyList and it works
    void search(graph&, int, int);
    bool alreadyVisited (int, std::vector<int>);
    int nodesExplored;
    std::vector<int>path;


};
#endif /* bfs_hpp */
