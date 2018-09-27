//
//  dijkstra.cpp
//  Lab1
//
//  Created by Blair Saunders on 9/25/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "dijkstra.h"
#include <tuple>
#include <algorithm>

using namespace std;
void dijkstra::search(graph& adjList, int src, int dst){
    bool destFound = false;
    bool done = false;

    int cmpWeight;
    int parent = src;
    int spot;

    vector<int>children;
    int weight;
    vector<tuple<int, int, int>> path_tracker;

    vector<tuple<int, int, int>> weight_vertex_path;
    vector<int>visited;
    visited.push_back(parent);
    weight_vertex_path.push_back(make_tuple(0, parent, -1));

    int finalWeight;

    while(destFound == false && done == false){

        if(weight_vertex_path.size()== 0){
            done = true;
        }
        else{
            parent = get<1>(weight_vertex_path[0]);
            adjList.getChildren(parent, children);
            for(int i = 0; i<children.size(); i++){
                //check if child is dst
                if(children[i] == dst){
                     weight = get<0>(weight_vertex_path[0]) + graphdata.getWeight(parent, children[i]);
                    //weight_vertex_path[spot] = make_tuple (weight, children[i], parent);
                     path_tracker.push_back(make_tuple (weight, children[i], parent));
                    destFound = true;


                }
                //check if child is on visited
                else if(alreadyVisited(children[i], visited) == true){
                    //do nothing, move on
                }

                //if the vertex is alreayd on the priorityList
                else if(onPriority(children[i], weight_vertex_path) == true){
                    //we need to compare the weight of this current path with the path found on the
                    //priority list
                    //to do so, we first need to get the current paths weight
                    //we do so buy getting the weight of the path that it came from (should be index 0
                    //on priorityList)
                    //and adding it to the weight from the parent to the child
                    //the comparing and swapping if needed
                    weight = get<0>(weight_vertex_path[0]) + graphdata.getWeight(parent, children[i]);
                    spot =spotOnPriority(children[i],weight_vertex_path );
                    if(weight < get<0>(weight_vertex_path[spot]) ){
                        weight_vertex_path[spot] = make_tuple (weight, children[i], parent);
                    }
                }
                else{
                    weight = get<0>(weight_vertex_path[0]) + graphdata.getWeight(parent, children[i]);
                    weight_vertex_path.push_back(make_tuple (weight, children[i], parent));
                }

            }
            visited.push_back(parent);
            path_tracker.push_back(weight_vertex_path[0]);
            weight_vertex_path.erase(weight_vertex_path.begin(),weight_vertex_path.begin()+1 );
            sort(weight_vertex_path.begin(), weight_vertex_path.end());


         }

    }


    nodesExplored = visited.size() + weight_vertex_path.size();

    //printing
    if(destFound == false){
        cout<<"no path found"<<endl;

    }
    else{

        int looking_for = dst;
        path.push_back(looking_for);
        bool pathComplete = false;
        int spot;

        while(pathComplete == false){
            for(int i = 0; i<path_tracker.size();i++){
                if(get<1>(path_tracker[i]) == looking_for){
                    spot = i;
                }
            }
            looking_for =get<2>(path_tracker[spot]);
            path.push_back(looking_for);
            if(looking_for == src){
                pathComplete = true;
            }
        }
        reverse(path.begin(), path.end());

    }


}










bool dijkstra::alreadyVisited (int v, std::vector<int>visited){
        bool wentThere = false;
        for(int i = 0; i<visited.size(); i++){
            if(v == visited[i]){
                wentThere = true;
            }
        }
        return wentThere;
    }



bool dijkstra::onPriority (int vertex, std::vector<std::tuple<int, int, int>> wvf){
    bool itsThere = false;
    for(int i = 0; i<wvf.size(); i++){
        if(get<1>(wvf[i]) == vertex){
            itsThere = true;
        }
    }
    return itsThere;
}

int dijkstra::spotOnPriority (int vertex, std::vector<std::tuple<int, int, int>> wvf){
    int spot;
    for(int i = 0; i<wvf.size(); i++){
        if(get<1>(wvf[i]) == vertex){
            spot = i;
        }
    }
    return spot;
}




