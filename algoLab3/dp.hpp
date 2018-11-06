#ifndef dp_hpp
#define dp_hpp
#include "TSP.hpp"
#include <stdio.h>

class dp: public TSP
{
public:
    void run(Graph & );
private:
    vector<int> tsp(int, vector<vector<float>>& );
    vector<vector<float>> setUp(int, vector<vector<float>>&);
    vector<int> solve(int, vector<vector<float>>&, vector<vector<float>>&);
    void tspT (int, vector<vector<float>>&);
   
};
#endif /* dp_hpp */
