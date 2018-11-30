//
//  fileReader.cpp
//  algoLab3
//
//  Created by Blair Saunders on 11/30/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "fileReader.hpp"
using namespace std;
void fileReader:: readFile(string file, vector<tuple<int, float, float, float>>& positions){
    Graph *g = new Graph();
    ifstream in;
    int one, count;
    float two, three, four;
    string line;
    in.open(file);
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
        
        positions.push_back(make_tuple(one, two, three, four));
        
    }
    in.close();
}
