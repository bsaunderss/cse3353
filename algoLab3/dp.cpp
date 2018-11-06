#include "dp.hpp"
#include <limits>
#include <float.h>
#include<algorithm>

using namespace std;

void dp::run(Graph & g){
    cout<<"~~Dynamic Programming TSP~~"<<endl;
    vector<int>path;
    path = tsp(g.size, g.matrix);
    cout<<"path: ";
    for(int i = 0; i<path.size(); i++){
        path[i]++;
        cout<<path[i]<<" ";
    }
    cout<<endl;
    int pathSize = g.getPathDistance(path);
    cout<<"path size: "<<pathSize<<endl;
}


vector<int> dp::tsp(int nodeCount, vector<vector<float>>& cost){
    vector<vector<float>>optimal = setUp(nodeCount, cost);
    vector<int>path;
    path = solve(nodeCount, cost, optimal);
    return path;
}



vector<vector<float>> dp::setUp (int nodeCount, vector<vector<float>>& distances){
    long chartSize = 1<<nodeCount;
    vector<vector<float>>optimal(chartSize,vector<float>(nodeCount));
    for(long outerloop = 1; outerloop<chartSize; outerloop+=2){
        for(int innerloop = 1; innerloop<nodeCount; innerloop++) {
            vector<int>subset;
            for(int mostinner = 1; mostinner<nodeCount; mostinner++){
                if(outerloop&(1<<mostinner)){
                    subset.push_back(mostinner);
                }
            }
            if(subset.size()>1){
                float smallestSubpath = 1000000.00;
                long t = outerloop &~(1<<innerloop);
                for(int iter = 0; iter<subset.size(); iter++){
                    int temp = subset[iter];
                    if(temp != innerloop && optimal[t][temp]+distances[temp][innerloop]<smallestSubpath){
                        smallestSubpath = optimal[t][temp]+distances[temp][innerloop];
                    }
                }
                optimal[outerloop][innerloop] = smallestSubpath;
            }
            else if(subset.size() == 1){
                optimal[outerloop][innerloop] = distances[0][innerloop];
            }
            else{}
        }
    }
    return optimal;
}

vector<int> dp::solve(int nodeCount, vector<vector<float>> &dist, vector<vector<float>> &o){
    vector<int>path;
    path.push_back(0);
    vector<bool>selected(nodeCount, false);
    selected[0] = true;
    long last = (1<<nodeCount)-1;
    int nextConnect, bestNode;
    for(int i = 0; i<nodeCount-1; i++) {
        nextConnect = path[path.size()-1];
        float smallestSubpath = 1000000.00;
        for(int j = 0; j<nodeCount; j++)
            if(selected[j] == 0 && o[last][j]+dist[j][nextConnect]<smallestSubpath) {
                smallestSubpath = o[last][j]+dist[j][nextConnect];
                bestNode = j;
            }
        path.push_back(bestNode);
        selected[bestNode] = true;
        last -= 1<<bestNode;
    }
    path.push_back(0);
    return path;
    
}

