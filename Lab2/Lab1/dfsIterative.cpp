//
//  dfs.cpp
//  Lab1
//
//  Created by Blair Saunders on 9/24/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "dfsIterative.h"
#include <algorithm>
using namespace std;

//with the list
void dfsIterative::search(graph& adjList, int src, int dst){
    nodesExplored = 0;
    bool destFound = false;
    bool done = false;


    stack<int>path_stack;

    visited.push_back(src);
    path_stack.push(src);

    int parent = src;
    int child;
    while(destFound == false && done == false){
        child = adjList.getNextToVisit(parent);
        if(child == -1){
            path_stack.pop();
            visited.pop_back();
            if(path_stack.size() == 0){
                done = true;
            }
            else{
                parent = path_stack.top();
            }
        }
        else if(child == dst){
            destFound = true;
            path_stack.push(child);
            visited.push_back(child);
        }
        else if(alreadyVisited(child, visited) == true){
            adjList.dfsDeleteChild(parent, child);
        }
        else{
            path_stack.push(child);
            visited.push_back(child);
            adjList.dfsDeleteChild(parent, child);
            parent = child;
        }

    }

    if(destFound == true){
        while(path_stack.size()>0){
            path.push_back(path_stack.top());
            path_stack.pop();
        }
    }

    reverse(path.begin(), path.end());
    nodesExplored = visited.size();
}





bool dfsIterative::alreadyVisited (int v, vector<int>visited){
    bool wentThere = false;
    for(int i = 0; i<visited.size(); i++){
        if(v == visited[i]){
            wentThere = true;
        }
    }
    return wentThere;
}







