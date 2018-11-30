//
//  usercatalog.cpp
//  Lab1
//
//  Created by Blair Saunders on 8/29/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "organizer.hpp"
#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <cstddef>
#include <sstream>
//#include "algorithm.hpp"
//#include "bubble.h"
using namespace std;
organizer::organizer()
{
    
}


//adding the file paths
void organizer::addFilePaths (vector<string>& paths){
    //example files I tested with
    //one with 4 nodes, one with 10 nodes
    vector<string>temp = {"4-nodes.txt", "10-nodes.txt"};
    for(int i = 0; i<temp.size(); i++){
        paths.push_back(temp[i]);
    }
}

//choosing the algorithms used
void organizer::addAlgoNames (vector<string>& names){
    
    string dp = "dp";
    string b = "brute";
    string g = "genetic";
    string t = "tabu";
    
    names.push_back(dp);
    names.push_back(b);
    names.push_back(g);
    names.push_back(t);
 
}


