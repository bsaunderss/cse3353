//
//  sa.cpp
//  algoLab3
//
//  Created by Blair Saunders on 12/8/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "sa.hpp"
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time

int sa::run(Graph & g){
    cout<<"~~Simmulated Annealning TSP~~"<<endl;
    init(g);
    
    float pathSize = g.getPathDistance(route);
    while(temperature > 0.00001 && pathSize > goal){
    vector<int>next = getNext(g);
    change = g.getPathDistance(next) - g.getPathDistance(route);
    if(change <0){
        route = next;
        temperature = temperature - 0.00001;
        pathSize = g.getPathDistance(route);
    }
    else{
        if(move() == true){
            route = next;
            temperature = temperature - 0.00001;
            pathSize = g.getPathDistance(route);
        }
    }
        
    }
    
    cout<<"path: ";
    for(int i = 0; i<route.size() ; i++){
        cout<<route[i]<<" ";
    }
    cout<<endl;
    cout<<"path size: "<<g.getPathDistance(route)<<endl;
    
    return g.getPathDistance(route);

    return 0;
}


void sa:: init(Graph & g){
    nodeCount = g.size;
    goal = g.smallest;
    int counter = nodeCount;
    
    route.push_back(1);
    for(int i = 2; i<=nodeCount; i++){
        route.push_back(i);
    }
    
    route.push_back(1);
    random_shuffle ( route.begin()+1, route.end()-1);
    temperature = 1.0;
}





vector<int> sa:: getNext(Graph & g){
    int highest = nodeCount -1;
    vector<int>temp (route);
    
    int spot1 = rand() % highest+1;
    int spot2 = rand() % highest+1;
    
    int element = temp[spot1];
    temp[spot1]= temp[spot2];
    temp[spot2]= element;
    return temp;
    
}




bool sa:: move(){
    probability = change/temperature;
    int random = rand() % 100;
    double r = random *1.0;
    if(r>probability){
        return true;
    }
    else{
        return false;
    }
}



