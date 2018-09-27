//
//  searchAlgo.cpp
//  Lab1
//
//  Created by Blair Saunders on 9/26/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "searchAlgo.h"


//
//  sort.cpp
//  Lab1
//
//  Created by Blair Saunders on 8/26/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "sortAlgo.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <cstddef>
#include <sstream>
#include <chrono>
#include <thread>

//used http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/ as a reference for the time function


using namespace std::chrono;

void searchAlgo:: load(string file){


}

void searchAlgo::load (){//[Takes a filename as and can read input data file]

    ifstream in;

    int one, two, three, four, count;
    string line;
    //reading the the graph
    in.open("graph.txt");
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
            else{
                two = stoi(number);
                spots.push_back(make_pair(one, two));
            }
            count++;
        }
    }
    in.close();

}

void searchAlgo:: select(string& algoName){
    name = algoName;
}

void searchAlgo:: selectStructure(string& structureName){
    structure = structureName;
}

void searchAlgo::setSourceAndDest(int s, int f){

    if(graphdata.isNode(s) == true){
        start = s;
    }
    else{
        bool inGraph = false;
        int num;
        while(inGraph == false){
            cout<<"You entered an invalid number for the starting node. Please enter a new one: ";
            cin>>num;
            inGraph = graphdata.isNode(num);
        }
        start = num;
    }

    if(graphdata.isNode(f) == true){
        finish = f;
    }
    else{
        bool inGraph = false;
        int num;
        while(inGraph == false){
            cout<<"You entered an invalid number for the ending node. Please enter a new one: ";
            cin>>num;
            inGraph = graphdata.isNode(num);
        }
        finish = num;
    }


}


void searchAlgo::execute (){//[Executes the search algorithm]
    adjacencyList l(spots);
    adjacencyMatrix m(spots);

    graph* list = &l;
    graph* matrix = &m;


    int s=start;
    int d=finish;


    if(name == "bfs recursive"){
        bfsRecursive bfs_rec;
        if(structure == "list"){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
           bfs_rec.search(*list, s, d);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time = duration_cast<duration<double>>(t2 - t1);
            path= bfs_rec.path;
            nodesExplored = bfs_rec.nodesExplored;

        }
        if(structure == "matrix"){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            bfs_rec.search(*matrix, s, d);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time = duration_cast<duration<double>>(t2 - t1);
            path= bfs_rec.path;
            nodesExplored = bfs_rec.nodesExplored;

        }
    }

    if(name == "bfs iterative"){
        bfsIterative bfs_iter;
        if(structure == "list"){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            bfs_iter.search(*list, s, d);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time = duration_cast<duration<double>>(t2 - t1);
            path= bfs_iter.path;
            nodesExplored = bfs_iter.nodesExplored;

        }
        if(structure == "matrix"){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            bfs_iter.search(*matrix, s, d);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time = duration_cast<duration<double>>(t2 - t1);
            path= bfs_iter.path;
            nodesExplored = bfs_iter.nodesExplored;

        }
    }

    if(name == "dfs iterative"){
        dfsIterative dfs_iter;
        if(structure == "list"){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            dfs_iter.search(*list, s, d);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time = duration_cast<duration<double>>(t2 - t1);
            path= dfs_iter.path;
            nodesExplored = dfs_iter.nodesExplored;

        }
        if(structure == "matrix"){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            dfs_iter.search(*matrix, s, d);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time = duration_cast<duration<double>>(t2 - t1);
            path= dfs_iter.path;
            nodesExplored = dfs_iter.nodesExplored;

        }
    }

    if(name == "dfs recursive"){
        dfsRecursive dfs_rec;
        if(structure == "list"){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            dfs_rec.search(*list, s, d);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time = duration_cast<duration<double>>(t2 - t1);
            path= dfs_rec.visited;
            nodesExplored = dfs_rec.nodesExplored;

        }
        if(structure == "matrix"){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            dfs_rec.search(*matrix, s, d);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time = duration_cast<duration<double>>(t2 - t1);
            path= dfs_rec.visited;
            nodesExplored = dfs_rec.nodesExplored;
        }
    }

    if(name == "a star"){
        astar a_star;
        if(structure == "list"){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            a_star.search(*list, s, d);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time = duration_cast<duration<double>>(t2 - t1);
            path= a_star.path;
            nodesExplored = a_star.nodesExplored;

        }
        if(structure == "matrix"){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            a_star.search(*matrix, s, d);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time = duration_cast<duration<double>>(t2 - t1);
            path= a_star.path;
            nodesExplored = a_star.nodesExplored;
        }

    }

    if(name == "dijkstra"){
        dijkstra dij;
        if(structure == "list"){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            dij.search(*list, s, d);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time = duration_cast<duration<double>>(t2 - t1);
            path= dij.path;
            nodesExplored = dij.nodesExplored;

        }
        if(structure == "matrix"){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            dij.search(*matrix, s, d);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();
            time = duration_cast<duration<double>>(t2 - t1);
            path= dij.path;
            nodesExplored = dij.nodesExplored;

        }

    }

}


void searchAlgo::display(){//[Prints solution to screen]

}


void searchAlgo::stats(){//[Prints algorithm name, execution time and number of

     cout<<"Algorithm Name: "<<name<<endl;
    cout<<"Structure used: " <<structure<<endl;
    cout<<"Path: ";
    for(int i = 0; i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
     cout<<"Number of Nodes in path: "<<path.size()<<endl;
    cout<<"Number of Nodes explored: "<<nodesExplored<<endl;
   cout<<"Time executing: "<<time.count()<<endl;
    if(path.size()>0){
        cout<<"Path Distance: "<<graphdata.getPathDistance(path)<<endl;
        cout<<"Path cost: "<<graphdata.getPathCost(path)<<endl<<endl;
    }



}



void searchAlgo::save (string file){//[Saves solution to file path given as input]
    ofstream fileout;
    fileout.open(file, fstream::app);
    if(!fileout){
        cout<<"Unable to open file"<<endl;
    }
    fileout<<"Alorithm Name: "<<name<<endl;
    fileout<<"Number of Nodes in path: "<<path.size()<<endl;
    fileout<<"Number of Nodes explored: "<<nodesExplored<<endl;
    fileout<<"Time executing: "<<time.count()<<endl;
    if(path.size()>0){
        fileout<<"Path Distance: "<<graphdata.getPathDistance(path)<<endl;
        fileout<<"Path cost: "<<graphdata.getPathCost(path)<<endl<<endl;
    }

    fileout<<endl;
    fileout.close();
}

void searchAlgo::configure (){

}

void searchAlgo::clearOutput (string file){

}








