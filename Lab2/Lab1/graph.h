//
//  graph.h
//  Lab1
//
//  Created by Blair Saunders on 9/24/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include <vector>
#include <iostream>
#include <utility>
#ifndef graph_hpp
#define graph_hpp
#include <list>

#include <stdio.h>

class graph
{
    public:
        virtual void dfsDeleteChild(int, int)=0;
        virtual int getNextToVisit (int)=0;
        virtual void getChildren(int, std::vector<int>&)=0;
        virtual int getNodeNumber ()=0;

        //std::vector<std::tuple<int, int, int>> weights;
        //std::vector<std::tuple<int, int, int, int>> positions;



};

#endif /* graph_hpp */
