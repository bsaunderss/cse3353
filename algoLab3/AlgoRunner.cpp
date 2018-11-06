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
    
    dynamic(*g);
    brute(*g);
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
                //two = stoi(number);
                two = stof(number);
            }
            
            else if (count == 3){
                //three = stoi(number);
                three = stof(number);
            }
            else{
                //four = stoi(number);
                four = stof(number);
            }
            count++;
        }
        g.addToPositions(one, two, three, four);
        g.addToNodes(one);

    }
    in.close();
    g.addToNodes(1);
}


void AlgoRunner::dynamic(Graph & g){
    trav = new dp();
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    trav->run(g);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t2 - t1);
    cout<<"Time executing: "<<time.count()<<endl<<endl;
}


void AlgoRunner::brute(Graph & g){
    trav = new bruteForce();
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    trav->run(g);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t2 - t1);
    cout<<"Time executing: "<<time.count()<<endl<<endl;
}
