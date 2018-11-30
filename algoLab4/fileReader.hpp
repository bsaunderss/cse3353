//
//  fileReader.hpp
//  algoLab3
//
//  Created by Blair Saunders on 11/30/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#ifndef fileReader_hpp
#define fileReader_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include <ctime>
#include <locale>
#include <ratio>
#include "Graph.hpp"
using namespace std;


class fileReader{
public:
    void readFile(string, vector<tuple<int, float, float, float>>&);
    
};
#endif /* fileReader_hpp */
