#include "bruteForce.hpp"
#include <algorithm>

void bruteForce:: run(Graph & g){
    cout<<"~~Brute Force TSP~~"<<endl;
    vector<int>nodes = g.nodes;
    std::sort(nodes.begin()+1, nodes.end()-1);
    do {
        addToSolutions(nodes, g);
    } while(std::next_permutation(nodes.begin()+1, nodes.end()-1));
    sort(solutions.begin(), solutions.end());
    cout<<"path: ";
    for(int i = 0; i<solutions[0].second.size(); i++){
        cout<<solutions[0].second[i]<<" ";
    }
    cout<<endl<<"path size: "<<solutions[0].first<<endl;
    
}



void bruteForce:: addToSolutions(vector<int>path, Graph & g){
    vector<int>temp;
    temp = path;
    float distance = g.getPathDistance(temp);
    solutions.push_back(make_pair(distance, temp));
    
}






