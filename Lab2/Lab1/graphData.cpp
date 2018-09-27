//
//  graphData.cpp
//  Lab1
//
//  Created by Blair Saunders on 9/26/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "graphData.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <cstddef>
#include <sstream>
#include <chrono>
#include <thread>


using namespace std;

graphData::graphData(){
    ifstream in;

    int one, two, three, four, count;
    string line;

    //reading in the weights
    in.open("weights.txt");
    if (!in) {
        cout << "Unable to open file";
        exit (EXIT_FAILURE);
    }
    while (!in.eof()){
        getline(in, line);
        stringstream lineStream(line);
        string number;
        count = 1;
        while(getline(lineStream,number,',') ){
            if(count ==1){
                one = stoi(number);
            }
            else if (count == 2){
                two = stoi(number);
            }
            else{
                three = stoi(number);
            }
            count++;
        }
        weights.push_back(make_tuple(one, two, three));
    }
    in.close();

    //reading in the position
    in.open("positions.txt");
    if (!in) {
        cout << "Unable to open file";
        exit (EXIT_FAILURE);
    }

    while (!in.eof()){
        getline(in, line);
        stringstream lineStream(line);
        string number;
        count = 1;
        while(getline(lineStream,number,',') ){
            if(count ==1){
                one = stoi(number);
            }
            else if (count == 2){
                two = stoi(number);
            }

            else if (count == 3){
                three = stoi(number);
            }
            else{
                four = stoi(number);
            }
            count++;
        }
        positions.push_back(make_tuple(one, two, three, four));
    }
    in.close();


}


int graphData::getDistance (int src, int dst){
    int distance;
    int src_pos;
    int dst_pos;
    for(int i = 0; i<positions.size(); i++){
        if(get<0>(positions[i])==src ){
            src_pos =i;
        }
        if(get<0>(positions[i])==src ){
            dst_pos =i;
        }
    }
    distance = abs(get<1>(positions[src])-get<1>(positions[dst])) + abs(get<2>(positions[src])-get<2>(positions[dst])) + abs(get<3>(positions[src])-get<3>(positions[dst]));

    return distance;


}


int graphData::getPathDistance(vector<int>p){
    int distanceTotal=0;
    for(int i = 0; i<p.size()-1; i++){
        distanceTotal += getDistance(p[i], p[i+1]);
    }
    return distanceTotal;

}



int graphData::getPathCost(vector<int>p){
    int costTotal=0;
    for(int i = 0; i<p.size()-1; i++){
        costTotal += getCost(p[i], p[i+1]);
    }
    return costTotal;

}

int graphData::getCost (int src, int dst){
    int distance;
    int src_pos;
    int dst_pos;
    for(int i = 0; i<positions.size(); i++){
        if(get<0>(positions[i])==src ){
            src_pos =i;
        }
        if(get<0>(positions[i])==src ){
            dst_pos =i;
        }
    }
    int weight = getWeight(src, dst);
    distance = abs(get<1>(positions[src])-get<1>(positions[dst])) + abs(get<2>(positions[src])-get<2>(positions[dst])) + abs(get<3>(positions[src])-get<3>(positions[dst]));

    distance = distance*(1+weight);
    return distance;



}



int graphData::getWeight (int src, int dst){
    int w =0;
    for(int i = 0; i<weights.size(); i++){
        if(get<0>(weights[i])==src && get<1>(weights[i])== dst ){
            w= get<2>(weights[i]);
            i = weights.size();
        }
    }
    return w;

}



bool graphData::isNode (int node){
    bool isThere = false;
    for(int i = 0; i<positions.size(); i++){
        if(node == get<0>(positions[i])){
            isThere = true;
        }

    }

    return isThere;




}








