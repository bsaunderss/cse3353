
#include "tabu.hpp"
#include <algorithm>


int tabu::run(Graph & g){
    cout<<"~~Tabu TSP~~"<<endl;
    counter = 0;
    createInitial(g);
    oneNeighorSwaps(g);
    twoNeighorSwaps(g);
    for(int i = 0; i<path.size(); i++){
        cout<<path[i]<<" ";
        
    }
    cout<<endl;
   int pathSize =g.getPathDistance(path);

    cout<<"path size: "<<pathSize<<endl;
    return pathSize;

}


void tabu::createInitial(Graph & g){
    vector<int>cities;
    
    for(int i = 2; i<=g.size; i++){
        cities.push_back(i);
    }
    path.push_back(1);
    int distance;
    int spot;
    while(path.size()<g.size){
        int next = path[path.size()-1];
        distance = g.getDistance(next, cities[0]);
        spot =0;
        for(int j = 1; j<cities.size(); j++){
            int newDistance = g.getDistance(next,cities[j]);
            if(newDistance<distance){
                distance = newDistance;
                spot =j;
            }
        }
        path.push_back(cities[spot]);
        cities.erase(cities.begin()+spot);
    }
    path.push_back(1);
    
  
    
}

void tabu::oneNeighorSwaps(Graph & g){
    int pathDistance, compareDistance, temp;
    for(int i = 1; i<path.size()-2; i++){
        pathDistance = g.getPathDistance(path);
        temp = path[i];
        path[i] = path[i+1];
        path[i+1] = temp;
        compareDistance = g.getPathDistance(path);
        
        if(pathDistance<compareDistance || checkList(path) == true){
            temp = path[i];
            path[i] = path[i+1];
            path[i+1] = temp;
        }
    }
    
}

void tabu::twoNeighorSwaps(Graph & g){
    int pathDistance, compareDistance, temp;
    for(int i = 1; i<path.size()-2; i++){
        for(int j = i+1; i<path.size()-1; i++){
            pathDistance = g.getPathDistance(path);
            temp = path[i];
            path[i] = path[j];
            path[j] = temp;
            compareDistance = g.getPathDistance(path);
            
            if(pathDistance<compareDistance || checkList(path) == true){
                temp = path[i];
                path[i] = path[j];
                path[j] = temp;
            }
        }
    }
    
}


bool tabu::checkList(vector<int>solVec){
    bool recent = false;
    if(tabuList.size()<5){
        for(int i = 0; i<tabuList.size(); i++){
            if(tabuList[i] == solVec ){
                recent = true;
            }
        }
        
    }
    
    else{
        int start = tabuList.size()-5;
        for(int i = start; i<tabuList.size(); i++){
            if(tabuList[i] == solVec ){
                recent = true;
            }
        }
    }
    return recent;
    
    
}










