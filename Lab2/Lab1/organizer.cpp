//
//  usercatalog.cpp
//  Lab1
//
//  Created by Blair Saunders on 8/29/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "organizer.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <cstddef>
#include <sstream>
#include "algorithm.h"
#include "bubble.h"
using namespace std;
organizer::organizer()
{

}


//adding the file paths
void organizer::addFilePaths (vector<string>& paths){
    vector<string>temp = {"size10orderRandom.txt", "size10orderReverse.txt", "size10orderUnique.txt", "size10order30Random.txt"};
    for(int i = 0; i<temp.size(); i++){
        paths.push_back(temp[i]);
    }
}

//choosing the algorithms used
void organizer::addAlgoNames (vector<string>& names){

    string dfsR = "dfs recursive";
    string dfsI = "dfs iterative";
    string bfsR = "bfs recursive";
    string bfsI = "bfs iterative";
    string aStar = "a star";
    string dij = "dijkstra";

    names.push_back(dfsR);
    names.push_back(dfsI);
    names.push_back(bfsR);
    names.push_back(bfsI);
    names.push_back(aStar);
    names.push_back(dij);
}

void organizer::addStructures (vector<string>& structures){
    structures.push_back("list");
    structures.push_back("matrix");
}

