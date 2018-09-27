//
//  graphData.h
//  Lab1
//
//  Created by Blair Saunders on 9/26/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef graphData_hpp
#define graphData_hpp

#include <stdio.h>
#include<vector>

class graphData{
    public:
        graphData();
        int getWeight (int, int);
        int getCost (int, int);
        int getDistance (int, int);
        int getPathDistance(std::vector<int>);
        int getPathCost(std::vector<int>);
        bool isNode (int);
        //int getPathWeight(std::vector<int>);

        std::vector<std::tuple<int, int, int>> weights;
        std::vector<std::tuple<int, int, int, int>> positions;


};
#endif /* graphData_hpp */

