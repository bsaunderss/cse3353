

//

//  algorithm.hpp

//  Lab1

//

//  Created by Blair Saunders on 8/26/18.

//  Copyright © 2018 Blair Saunders. All rights reserved.

//


#ifndef algorithm_hpp

#define algorithm_hpp

#include <stdio.h>

#include <string>

#include <chrono>

#include <thread>

#include <ctime>

#include <ratio>


using namespace std;


class algorithm{

public:

    algorithm() {}

    virtual void load () = 0;

    virtual void selectStructure(string&)=0;

    virtual void load (string) = 0; //[Takes a filename as and can read input data file]

    virtual void execute ()= 0; //[Executes the search algorithm]

    virtual void display()= 0; //[Prints solution to screen]

    virtual void stats()= 0; //[Prints algorithm name, execution time and number of records analyzed to screen in a readable format]

    virtual void save (string)= 0; //[Saves solution to file path given as input]

    virtual void configure ()= 0;// [Future expandability ]

    virtual void select (string&) = 0;//[enum or int or id passed as input and loads corresponding algorithm to interface]

    virtual void clearOutput(string)=0;

    virtual void setSourceAndDest(int, int)=0;

private:

    string name;

    std::chrono::duration<double>time;

    int records;

    string inputfile;



};



#endif /* algorithm_hpp */
