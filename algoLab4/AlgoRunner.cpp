//
//  organizer.cpp
//  lab3
//
//  Created by Blair Saunders on 11/3/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "AlgoRunner.hpp"

using namespace std;
using namespace std::chrono;

AlgoRunner::AlgoRunner(){}

void AlgoRunner:: go(){
    Graph *g = new Graph();
    readInPositions(*g);
    g->createGraph();
    
  
    //run all the algorithms
    dynamic(*g);
    brute(*g);
    tabuAlgo(*g);
    geneticAlgo(*g);
}


void AlgoRunner:: readInPositions(Graph & g){
    ifstream in;
    int one, count;
    float two, three, four;
    string line;
    in.open("4-nodes.txt");
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
                two = stof(number);
            }
            
            else if (count == 3){
                three = stof(number);
            }
            else{
                four = stof(number);
            }
            count++;
        }
        g.addToPositions(one, two, three, four);


    }
    in.close();
    
 
}


void AlgoRunner:: testing(){
    
    int i =7;//node count
    int loops =15;
    vector<vector<double>> timesAv;
        for(int j = 0; j<loops; j++){
            cout<<"New Graph"<<endl;
            Graph *g = new Graph();
            vector<double> times;
            for(int k = 1; k<=i; k++){
                
                float x = (rand() / (float)RAND_MAX * 19) + 1;
                float y = (rand() / (float)RAND_MAX * 19) + 1;
                float z = (rand() / (float)RAND_MAX * 19) + 1;
                 g->addToPositions(k, x, y, z);
            }
             g->createGraph();
           
            
            dynamic(*g);
            times.push_back(time.count());
            times.push_back(time.count());
            
          
            
            tabuAlgo(*g);
            times.push_back(time.count());
            times.push_back(time.count());
            
            timesAv.push_back(times);
            
            
            
            
        }
    vector<double>averageTimes;
    for(int i = 0; i<4; i++){
        double average=0;
        for(int j= 0; j<loops; j++){
            average += timesAv[j][i];
        }
        average = average/loops;
        averageTimes.push_back(average);
        
    }
        
        
    for(int i = 0; i<averageTimes.size(); i++){
        
        cout<<averageTimes[i]<<endl;
    }
    
    
    
    
    
}


void AlgoRunner::dynamic(Graph & g){
    trav = new dp();
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    smallestPathSize = trav->run(g);
    g.setSmallestPathSize(smallestPathSize);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t2 - t1);
    cout<<"Time executing: "<<time.count()<<endl<<endl;
}


void AlgoRunner::brute(Graph & g){
    trav = new bruteForce();
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    smallestPathSize = trav->run(g);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t2 - t1);
    cout<<"Time executing: "<<time.count()<<endl<<endl;
}

void AlgoRunner::geneticAlgo(Graph & g){
    trav = new genetic();
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int temp = trav->run(g);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t2 - t1);
    cout<<"Time executing: "<<time.count()<<endl<<endl;
}

void AlgoRunner::tabuAlgo(Graph & g){
    trav = new tabu();
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int temp = trav->run(g);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t2 - t1);
    cout<<"Time executing: "<<time.count()<<endl<<endl;
}



