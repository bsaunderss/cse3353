//
//  dfs.h
//  Lab1
//
//  Created by Blair Saunders on 9/24/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef dfs_hpp
#define dfs_hpp

#include <stdio.h>
#include <vector>
#include <stack>
#include "adjacencyList.h"
#include "adjacencyMatrix.h"

class dfsIterative{
    public:
        void search(graph&, int, int);
        bool alreadyVisited (int, std::vector<int>);
        std::vector<int>path;
        std::vector<int>visited;
        int nodesExplored;

};
#endif /* dfs_hpp */
