//
//  merge.hpp
//  Lab1
//
//  Created by Blair Saunders on 9/3/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef merge_h
#define merge_h

#include <stdio.h>
#include <vector>
#include <stdio.h>
#include <string>

class Merge{
public:
    void mergesort (std::vector<int>&);
    void divide (std::vector<int>&, int, int);//divides the vector into smaller parts
    void join (std::vector<int>&, int, int, int);//sorts and joins the smaller parts of the vector back together
private:
    std::string stage;
};
#endif /* merge_h */
