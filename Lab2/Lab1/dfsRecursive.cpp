//
//  dfsRecursive.cpp
//  Lab1
//
//  Created by Blair Saunders on 9/25/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "dfsRecursive.h"

using namespace std;

void dfsRecursive::search(graph& adjList, int src, int dst){

    //nodesExplored++;
    if(alreadyVisited(src) == false){
        visited.push_back(src);
        path_stack.push(src);
    }

    int parent = src;
    int child;

        child = adjList.getNextToVisit(parent);
        if(child == -1){
            path_stack.pop();
            visited.pop_back();
            if(path_stack.size() == 0){
                done = true;
                go = false;
            }
            else{
                parent = path_stack.top();
                go = true;
            }
        }
        else if(child == dst){
            destFound = true;
            path_stack.push(child);
            visited.push_back(child);
            go = false;
        }
        else if(alreadyVisited(child) == true){
            adjList.dfsDeleteChild(parent, child);
            go = true;
        }
        else{

            path_stack.push(child);
            visited.push_back(child);
            adjList.dfsDeleteChild(parent, child);
            parent = child;
            go = true;
        }

    if(go == true){
        search(adjList, parent,dst);
    }

    else{
        nodesExplored = visited.size();
    }





}


void dfsRecursive::printV(){

    for(int i = 0; i<visited.size(); i++){
        cout<<visited[i]<<" ";
    }
    cout<<endl;

}




bool dfsRecursive::alreadyVisited (int v){
    bool wentThere = false;
    for(int i = 0; i<visited.size(); i++){
        if(v == visited[i]){
            wentThere = true;
        }
    }
    return wentThere;
}




