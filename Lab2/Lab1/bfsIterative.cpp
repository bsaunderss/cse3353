//
//  bfs.cpp
//  Lab1
//
//  Created by Blair Saunders on 9/25/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "bfsIterative.h"
#include <algorithm>

using namespace std;



void bfsIterative::search(graph& adjList, int src, int dst){
    nodesExplored = 0;
    bool destFound = false;
    bool done = false;
    int counter;
    vector<int>children;

    vector<int>visited;
    vector<pair<int,int>> child_and_parent;

    int parent = src;
    int visiting = 0;
    visited.push_back(parent);
    while(destFound == false && done == false){
        //nodesExplored++;
        adjList.getChildren(parent, children);
        counter = 0;
        while(counter<children.size()){
            if(children[counter] == dst){
               // nodesExplored++;
                counter = children.size();
                destFound = true;
                child_and_parent.push_back(make_pair(dst, parent));
            }

            if(alreadyVisited(children[counter], visited ) == false){
                visited.push_back(children[counter]);
                child_and_parent.push_back(make_pair(children[counter], parent));
            }
            counter++;
        }

        if((visiting+1)== child_and_parent.size()){
            done = true;
        }
        else{
            parent = child_and_parent[visiting].first;
            visiting++;
        }
    }
    if(destFound == false){
        cout<<"no path found"<<endl;
        nodesExplored = visited.size();
    }
    else{
        int looking_for = dst;
        path.push_back(looking_for);
        bool pathComplete = false;
        int spot;

        while(pathComplete == false){
            for(int i = 0; i<child_and_parent.size();i++){
                if(child_and_parent[i].first == looking_for){
                    spot = i;
                }
            }
            looking_for = child_and_parent[spot].second;
            path.push_back(looking_for);
            if(looking_for == src){
                pathComplete = true;
            }
        }
        reverse(path.begin(), path.end());
         nodesExplored = visited.size();
    }

}


bool bfsIterative::alreadyVisited (int v, vector<int>visited){
    bool wentThere = false;
    for(int i = 0; i<visited.size(); i++){
        if(v == visited[i]){
            wentThere = true;
        }
    }
    return wentThere;
}
