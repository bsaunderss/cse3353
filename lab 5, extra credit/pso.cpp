
//
//  pso.cpp
//  algoLab3
//
//  Created by Blair Saunders on 12/8/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "pso.hpp"


int pso:: run(Graph & g){
    cout<<"~~PSO TSP~~"<<endl;
    init(g);
    while(g.getPathDistance(globalBest)>goal){
            for(int i = 0; i<particleVector.size(); i++){
                move(particleVector[i], g);
            }
    }
    print(globalBest);
    cout<<"path Size: "<<g.getPathDistance(globalBest)<<endl;
    return g.getPathDistance(globalBest) ;
}


void pso::init(Graph & g ){
    goal = g.smallest;
    nodeCount = g.size;
    particle*p = new particle (g.size);
    for(int i = 0; i<20; i++){
        particle*p = new particle (g.size);
        particleVector.push_back(*p);
    }
    float bestDistance = 10000000000.00;
    int temp;
    for(int i = 0; i<particleVector.size(); i++){
        temp = g.getPathDistance(particleVector[i].currentPath);
        
        if(temp < bestDistance){
            globalBest = particleVector[i].bestPath;
            bestDistance = temp;
        }
    }
    
}

void pso:: move (particle& p, Graph &g ){
    
    
    int pathSize = g.getPathDistance(p.currentPath);
    if(p.noVelocity<3){
        longestLink(p.currentPath, g);
    }
    
    if(p.noVelocity >= 3 & p.noVelocity <= 6 ){
        p.currentPath = p.bestPath;
        longestLink(p.currentPath, g);
    }
    
    if(p.noVelocity > 6){
        p.currentPath = globalBest;
        longestLink(p.currentPath, g);
    }
    
    if(pathSize<g.getPathDistance(p.currentPath)){
        p.noVelocity++;
    }
    else{
        p.noVelocity =0;
    }
    
    if(g.getPathDistance(p.currentPath) <
       g.getPathDistance(globalBest) ){
        globalBest =p.currentPath;
        
    }
    
    
    if(g.getPathDistance(p.currentPath) <
       g.getPathDistance(p.bestPath) ){
        p.bestPath =p.currentPath;
    }
    
}

void pso::longestLink(vector<int>& vec, Graph & g){
    int size;
    float longestLink =0;
    int spot1 =1;
    int spot2 =2;
    for(int i = 0; i<vec.size()-1; i++){
        if(g.getDistance(vec[i], vec[i+1]) > longestLink){
            int spot1 =i;
            int spot2 = i+1;
        }
    }
    int switchSpot;
    if(spot1 == 0 && spot2 == 1){
        switchSpot = spot2;
    }
    else if(spot1== vec.size()-1 &&spot1==vec.size()-2 ){
        switchSpot = spot1;
    }
    else{
        int rando = rand() % 2;
        
        if(rando == 0){
            switchSpot = spot1;
        }
        else{
            switchSpot = spot2;
        }
    }
    
    int range= g.size -1;
    int secondSwitch = rand() % range+1;
    while(secondSwitch == switchSpot)
        secondSwitch = rand() % range+1;
    int t = vec[switchSpot];
    vec[switchSpot] = vec[secondSwitch];
    vec[secondSwitch] =  t;
}








void pso::print(vector<int>t){
    cout<<"path: ";
    for(int i = 0; i<t.size(); i++){
        cout<<t[i]<<" ";
    }
    cout<<endl;
    
    
}

