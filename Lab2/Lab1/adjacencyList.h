//
//  adjacencyList.h
//  Lab1
//
//  Created by Blair Saunders on 9/24/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef adjacencyList_hpp
#define adjacencyList_hpp
#include <vector>
#include <utility>
#include <iostream>
#include <cmath>

#include <stdio.h>
#include "graph.h"


class adjacencyList: public graph{
    public:
    adjacencyList(std::vector<std::pair<int,int>>);
        void dfsDeleteChild(int, int);
        int getNextToVisit (int);
        void getChildren(int, std::vector<int>&);
        int getNodeNumber();

        std::vector<std::vector<int>> adj;






};
#endif /* adjacencyList_hpp */
