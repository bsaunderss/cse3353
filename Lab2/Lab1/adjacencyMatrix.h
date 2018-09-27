//
//  adjacencyMatrix.h
//  Lab1
//
//  Created by Blair Saunders on 9/24/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef adjacencyMatrix_hpp
#define adjacencyMatrix_hpp
#include <vector>
#include <utility>
#include <iostream>
#include <tuple>
#include <stdio.h>
#include "graph.h"




class adjacencyMatrix:public graph{
    public:
        adjacencyMatrix(std::vector<std::pair<int,int>>);
        void dfsDeleteChild(int, int);
        int getNextToVisit (int);
        void getChildren(int, std::vector<int>&);
        int getNodeNumber();


        int **adj;
        int size;
        bool *visited;

};

#endif /* adjacencyMatrix_hpp */
