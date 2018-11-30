#include "Graph.hpp"
#include<math.h>
using namespace std;

Graph::Graph(){ }



void Graph::createGraph(vector<tuple<int, float, float, float>>& p){
    for(int i = 0; i<p.size(); i++){
        positions.push_back(p[i]);
    }
}
void Graph:: createGraph(){
    size = positions.size();
  
    for(int i = 1; i<=size; i++){
        vector<float>temp(size, 0);
        for(int j = 1; j<=size; j++){
            temp[j-1]= getDistance(i, j);
        }
        matrix.push_back(temp);
    }
}


void Graph:: addToPositions(int node, float x, float y, float z){
    positions.push_back(make_tuple(node, x, y, z));
}


//void Graph:: addToNodes(int nodeID){
   // nodes.push_back(nodeID);
//}


float Graph::getDistance (int src, int dst){
    float distance;
    float x_one =get<1>(positions[src-1]);
    float x_two =get<1>(positions[dst-1]);
    float y_one =get<2>(positions[src-1]);
    float y_two =get<2>(positions[dst-1]);
    float z_one =get<3>(positions[src-1]);
    float z_two =get<3>(positions[dst-1]);
    float dif_x = x_two-x_one;
    float dif_y = y_two-y_one;
    float dif_z = z_two-z_one;
    int under =((dif_x)*(dif_x))+((dif_y)*(dif_y))+((dif_z)*(dif_z));
    distance = sqrt(under);
    return distance;
}


float Graph::getPathDistance(vector<int>p){
    int distanceTotal=0;
    //float distanceTotal = 0;
    for(int i = 0; i<p.size()-1; i++){
        distanceTotal += getDistance(p[i], p[i+1]);
    }
    return distanceTotal;
    
}

void Graph::setSmallestPathSize(int s){
    
    smallest=s;
}





