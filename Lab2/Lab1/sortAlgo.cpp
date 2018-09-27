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
void sortAlgo::load (string fileName){//[Takes a filename as and can read input data file]
    //the data vector holds the list of intergers
    //it needs to be clear before taking new integers in
    data.clear();
    inputfile = fileName;
    ifstream file;
    file.open(fileName);
    if (!file) {
        cout << "Unable to open file";
    }
    int number;
    int recordCount=0;
    while(!file.eof()){
        recordCount++;
        file>>number;
        data.push_back(number);
    }
    records = recordCount;

}

void sortAlgo:: select(string& algoName){
    name = algoName;
}


void sortAlgo::execute (){//[Executes the search algorithm]
    if (name == "bubble"){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        b.bubblesort(data);
         high_resolution_clock::time_point t2 = high_resolution_clock::now();
        time = duration_cast<duration<double>>(t2 - t1);

    }
    else if (name == "merge"){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        m.mergesort(data);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
         time = duration_cast<duration<double>>(t2 - t1);

    }
    else if (name == "insertion"){
       high_resolution_clock::time_point t1 = high_resolution_clock::now();
        i.insertionsort(data);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
         time = duration_cast<duration<double>>(t2 - t1);

    }

   // display();
}


void sortAlgo::display(){//[Prints solution to screen]
    int size = data.size();
    int i;
    for(i = 0; i<size; i++){
        cout<<data.at(i)<<endl;
    }
}


void sortAlgo::stats(){//[Prints algorithm name, execution time and number of records analyzed to screen in a readable format]
    cout<<"File Name: "<<inputfile<<endl;
    cout<<"Algorithm Name: "<<name<<" sort"<<endl;
    cout<<"Records: "<<records<<endl;
    cout<<"Time: "<<time.count()<<endl<<endl;
}



void sortAlgo::save (string file){//[Saves solution to file path given as input]
    ofstream fileout;
    fileout.open(file, fstream::app);
    if(!fileout){
        cout<<"Unable to open file"<<endl;
    }
    fileout<<"Alorithm Name: "<<name<<endl;
    fileout<<"Data size: "<<records<<endl;
    fileout<<"Sorted Data:"<<endl;
    for(int i = 0; i<data.size(); i++){
        fileout<<data[i]<<endl;
    }
    fileout<<endl;
    fileout.close();
}

void sortAlgo::clearOutput (string file){
    ofstream fileout;
    fileout.open(file);
    if(!fileout){
        cout<<"Unable to open file"<<endl;
    }
    fileout<<endl;
    fileout.close();
}

void sortAlgo::configure (){

}

void sortAlgo::load (){

}

void sortAlgo::selectStructure (string&s){

}



