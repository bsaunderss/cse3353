//
//  adjacencyMatrix.cpp
//  Lab1
//
//  Created by Blair Saunders on 9/24/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "adjacencyMatrix.h"


using namespace std;
adjacencyMatrix::adjacencyMatrix(std::vector<std::pair<int,int>> list){
    int highestNumber = 0;

    for(int i = 0; i<list.size(); i++){
        if(list[i].first > highestNumber){
            highestNumber =list[i].first;
        }
        if(list[i].second > highestNumber){
            highestNumber =list[i].second;
        }
    }
    size = highestNumber+1;

    visited = new bool[size];
    adj = new int* [size];
    for (int i = 0; i < size; i++){
        adj[i] = new int [size];
        for(int j = 0; j < size; j++){
            adj[i][j] = 0;
        }
    }

    int one, two;
    for(int i = 0; i<list.size(); i++){
        one = list[i].first;
        two = list[i].second;

        adj[one][two] =1;

    }


}


/*void adjacencyMatrix::display()
{
    int i,j;
    for(i = 0;i < size;i++)
    {
        for(j = 0; j < size; j++)
        cout<<adj[i][j]<<"  ";
        cout<<endl;
    }
}*/




void adjacencyMatrix::dfsDeleteChild(int parent, int child){
    adj[parent][child] = 0;
}




int adjacencyMatrix::getNextToVisit (int parent){
    bool nextFound = false;
    int start = 0;
    int next;

    while(nextFound == false && start<size){
        if(adj[parent][start] == 1){
            next = start;
            nextFound = true;
        }
        else{
            start++;
        }
    }


    if(nextFound == false){
        next = -1;
    }

    return next;

}

void adjacencyMatrix::getChildren(int parent, std::vector<int>& children){
    children.clear();

    for(int i = 0; i<size; i++){
        if(adj[parent][i] == 1){
            children.push_back(i);
        }
    }


}

int adjacencyMatrix:: getNodeNumber(){
    return size;
}
