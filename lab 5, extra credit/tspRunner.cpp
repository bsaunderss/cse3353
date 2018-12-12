

#include "tspRunner.hpp"
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

void tspRunner:: load(std::string file){
    positions.clear();
    fr.readFile(file, positions);
}




void tspRunner::execute (){//[Executes the search algorithm]
    Graph *g = new Graph(); 
    g->createGraph(positions);
    g->createGraph();
    
    if(name == "dp"){
        setSmallest = false;
        trav = new dp();
    }
    
    if(name == "brute"){
        setSmallest = false;
        trav = new bruteForce();
    }
    
    if(name == "genetic"){
        setSmallest = true;
         trav = new genetic();
    }
    
    if(name == "tabu"){
         setSmallest = true;
         trav = new tabu();
    }
    
    if(name == "sa"){
        setSmallest = true;
        trav = new sa();
    }
    
    if(name == "pso"){
        setSmallest = true;
        trav = new pso();
       
    }
    
    excuteAlgo(*g, trav);
    
}

void tspRunner:: excuteAlgo(Graph & g, TSP * trav){
    if(setSmallest == true)
         g.setSmallestPathSize(smallestPathSize);
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    
    if(setSmallest == false)
        smallestPathSize = trav->run(g);
    
    else
        temp =trav->run(g);
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    time = duration_cast<duration<double>>(t2 - t1);
    cout<<"Time executing: "<<time.count()<<endl<<endl;
    
    
}

void tspRunner:: select(string & algoName){
    name = algoName;
}








void tspRunner:: testing(){
    
    vector<string> names {"dp", "sa", "pso"};
    
    //starting node count that you want to test
    int start = 10;
    
    //go until the ending node count you want to test
    while(start<=10){
    
        //i is equal to the node count
        int i =start;
        
        //the ampunt of loops you want to test for
        int loops =3;
        
        //the time averages
        vector<vector<double>> timesAv;
         vector<vector<double>> differenceFromOptimal;
        vector<double> t (loops);
    
        
        timesAv.push_back(t);
        timesAv.push_back(t);
        timesAv.push_back(t);
      
        
        differenceFromOptimal.push_back(t);
        differenceFromOptimal.push_back(t);
        differenceFromOptimal.push_back(t);

        
        for(int j = 0; j<loops; j++){
            cout<<"LOOP: " <<j<<endl;
            cout<<"New Graph"<<endl;
            positions.clear();
            Graph *g = new Graph();
            vector<double> times;
            for(int k = 1; k<=i; k++){
                float x = (rand() / (float)RAND_MAX * 19) + 1;
                float y = (rand() / (float)RAND_MAX * 19) + 1;
                float z = (rand() / (float)RAND_MAX * 19) + 1;
                 positions.push_back(make_tuple(k, x, y, z));
            }
            
            for(int i = 0; i<names.size(); i++){
                select(names[i]);
                execute();
                
                if(names[i] == "dp"){
                    timesAv[0][j]= time.count();
                    differenceFromOptimal[0][j] =0 ;
                    
                }
                if(names[i] == "sa"){
                     timesAv[1][j]= time.count();
                     differenceFromOptimal[1][j] = temp- smallestPathSize;
                }
                
               if(names[i]== "pso"){
                    timesAv[2][j]= time.count();
                    differenceFromOptimal[2][j] = temp- smallestPathSize;
                }
              
               
                
            }
            
        }
        
        

        //after testing for a specific node count, the average time for that node count is displayed
        
        cout<<"----------------------------------"<<endl;
        cout<<"Node Count: "<<i<<endl<<endl;
        
        cout<<"timing:"<<endl;
        
        for(int i = 0; i<names.size(); i++){
            double time = 0;
            for(int j = 0; j<loops; j++){
                time+= timesAv[i][j];
            }
            time= time/loops;
            if(i == 0){
                cout<<"DP: ";
            }
            else if(i == 1){
                cout<<"SA: ";
            }
            else if (i == 2){
                cout<<"PSO: ";
            }
            
            cout<<time<<endl;
            
        }
        
        cout<<"Difference from optimal: "<<endl;
        for(int i = 0; i<names.size(); i++){
            double average = 0;
            for(int j = 0; j<loops; j++){
                average+= differenceFromOptimal[i][j];
            }
            
            average= average/loops;
            if(i == 0){
                cout<<"DP: ";
            }
            else if(i == 1){
                cout<<"SA: ";
            }
            else if (i == 2){
                cout<<"PSO: ";
            }
          
           
            cout<<average<<endl;
        }
         cout<<"----------------------------------"<<endl<<endl;
        
        
        start++;
        
        }
    
}










