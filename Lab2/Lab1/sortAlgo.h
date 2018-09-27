//
//  sort.h
//  Lab1
//
//  Created by Blair Saunders on 8/26/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <stdio.h>

#include "algorithm.h"
#include "bubble.h"
#include "Merge.h"
#include "insertion.h"

using namespace std;
class sortAlgo: public algorithm {
    void load();
    void load (string); //[Takes a filename as and can read input data file]
    void execute (); //[Executes the algorithm]
    void display(); //[Prints solution to screen]
    void stats(); //[Prints algorithm name, execution time and number of records analyzed to screen in a readable format]
    void save (string); //[Saves solution to file path given as input]
    void configure ();// [Future expandability ]
    void select (string&);//[enum or int or id passed as input and loads corresponding algorithm to interface]
    void clearOutput(string);
    void selectStructure(string&);

private:
    string name;//algoName
    std::chrono::duration<double> time;//how quickly it executes
    int records;
    string inputfile;
    vector<int> data;//vector getting sorted

    bubble b;
    Merge m;
    insertion i;

};

#endif /* sort_h */
