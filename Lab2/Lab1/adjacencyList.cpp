//
//  adjacencyList.cpp
//  Lab1
//
//  Created by Blair Saunders on 9/24/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "adjacencyList.h"
using namespace std;
adjacencyList::adjacencyList(std::vector<std::pair<int,int>> list){
    int one, two, spot;
    bool firstAlreadyThere;
    std::vector<int>newFirst;

    for(int i = 0; i<list.size(); i++){
        firstAlreadyThere= false;
        one = list[i].first;
        two = list[i].second;

        for(int j = 0; j<adj.size();j++ ){
           firstAlreadyThere = false;
            if(adj[j][0] == one){
                firstAlreadyThere = true;
                spot = j;
            }
        }
        if(firstAlreadyThere == true){
            adj[spot].push_back(two);

        }
        else{
            std::vector<int>*newVector = new std::vector<int>;
            newVector-> push_back(one);
            newVector->push_back(two);
            adj.push_back(*newVector);

            delete newVector;
        }
    }
}


void adjacencyList::dfsDeleteChild(int parent, int child){
    int parentSpot, childSpot;
    for(int i = 0; i<adj.size(); i++){
        if(adj[i][0] == parent){
            parentSpot = i;
        }
    }
    for(int i = 0; i<adj[parentSpot].size(); i++){
        if(adj[parentSpot][i] == child){
            childSpot = i;
        }
    }
    adj[parentSpot].erase(adj[parentSpot].begin() + childSpot);
}




int adjacencyList::getNextToVisit (int parent){
    bool parentFound = false;
    int start = 0;
    while(parentFound == false && start<adj.size()){
        if(adj[start][0] == parent){
            parentFound = true;
        }
        else{
            start++;
        }
    }
    if(adj[start].size()<2){
        return -1;
    }
    else{
        return adj[start][1];
    }
}



void adjacencyList::getChildren(int parent, std::vector<int>& children){
    children.clear();
    bool parentFound = false;
    int start = 0;
    while(parentFound == false && start<adj.size()){
        if(adj[start][0] == parent){
            parentFound = true;
        }
        else{
            start++;
        }
    }
    for(int i = 1; i<adj[start].size(); i++){
        children.push_back(adj[start][i]);
    }
}

int adjacencyList:: getNodeNumber(){
    return adj.size();
}

