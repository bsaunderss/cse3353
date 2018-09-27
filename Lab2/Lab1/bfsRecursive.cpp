//
//  bfsRecursive.cpp
//  Lab1
//
//  Created by Blair Saunders on 9/26/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "bfsRecursive.h"
using namespace std;
#include <algorithm>

void bfsRecursive::search(graph & adjList, int src, int dst, int visiting){
    int parent = src;
    adjList.getChildren(parent, children);
    counter = 0;
    while(counter<children.size()){
        if(children[counter] == dst){
            counter = children.size();
            destFound = true;
            parent_and_child.push_back(make_pair(dst, parent));
        }

        if(alreadyVisited(children[counter], visited ) == false){
            visited.push_back(children[counter]);
            parent_and_child.push_back(make_pair(children[counter], parent));
        }
        counter++;
    }

    //cout<<visiting+1<<" "<<parent_and_child.size()<<endl;
    if((visiting+1)== parent_and_child.size()){
        done = true;
    }

    if(destFound == false && done == false){
        parent = parent_and_child[visiting].first;
        visiting++;
        search(adjList, parent, dst, visiting);
    }

    else{

        if(done== true){
            nodesExplored = visited.size();
        }

        else{
        //looking for starts are the destination
        int looking_for = dst;
        //add the destination to path
        path.push_back(looking_for);
        //set path complete to false
        bool pathComplete = false;
        int spot;

        //while path complete is false
        while(pathComplete == false){
            //search through the parent_and_child vector
            for(int i = 0; i<parent_and_child.size();i++){
                //if the first item in the pair equals looking for
                if(parent_and_child[i].first == looking_for){
                    //set spot equal to i
                    spot = i;
                }
            }
            looking_for = parent_and_child[spot].second;
            path.push_back(looking_for);
            if(looking_for == source){
                pathComplete = true;
            }
        }
        reverse(path.begin(), path.end());
        nodesExplored = visited.size();
        nodesExplored++;

        }
    }


}





void bfsRecursive::search(graph & adjList, int src, int dst){
    source = src;
    parent_and_child.push_back(make_pair(source, -1));
    search(adjList, src, dst, 0);

}


bool bfsRecursive::alreadyVisited (int v, vector<int>visited){
    bool wentThere = false;
    for(int i = 0; i<visited.size(); i++){
        if(v == visited[i]){
            wentThere = true;
        }
    }
    return wentThere;
}
