


//http://www.cplusplus.com/reference/algorithm/random_shuffle/

#include "genetic.hpp"
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>

using namespace std;
int genetic::run(Graph & g){
    cout<<"~~Genetic TSP~~"<<endl;
    nodeCount = g.size;
    goal = g.smallest;
    int counter = nodeCount;
    while(counter>0){
        vector<int>route;
        route.push_back(1);
        for(int i = 2; i<=nodeCount; i++){
            route.push_back(i);
        }
        route.push_back(1);
        random_shuffle ( route.begin()+1, route.end()-1);
        int pathSize =g.getPathDistance(route);
        pair<int, vector<int>> sizeAndPath (pathSize, route);
        randomRoutes.push_back(sizeAndPath);
        counter--;
    }
    sort(randomRoutes.begin(), randomRoutes.end());
    loop = 0;
    return tsp(g);
    
    
    
}

int genetic:: tsp (Graph & g){
    int pSize = randomRoutes[0].first;
    int c = 0;
    int mult = 35;
    int stop = randomRoutes.size();
    goal = g.smallest;
    while(pSize>goal){
        int one;
        int size = randomRoutes.size();
        if(randomRoutes.size()%2 != 0){
            size--;
        }
        
        int two = rand() % randomRoutes.size();
        for(int i = 0; i<10; i++){
            one = rand() % randomRoutes.size();
            offspring(i,one,g);
        }
        
        
        //woooooah
        for(int i = 0; i<100; i++){
            mutate(g);
        }
        
        sort(randomRoutes.begin(), randomRoutes.end());
        pSize = randomRoutes[0].first;
        c++;
        
        
    }
    
    
    cout<<"path: ";
    for(int i = 0; i<randomRoutes[0].second.size(); i++){
        cout<<randomRoutes[0].second[i]<<" ";
        
    }
    cout<<endl;
    cout<<"path size: "<<randomRoutes[0].first<<endl;
    
    return randomRoutes[0].first;
    
    
}

void genetic::offspring(int one, int two, Graph & g){
    vector<int>parent1 = randomRoutes[one].second;
    vector<int>parent2 = randomRoutes[two].second;
    
    vector<int>child(nodeCount+1);
    
    //tested it at the half way point
    //tested at the 75% point
    int spot = rand() % nodeCount;
    
    
    for(int i = spot; i<parent1.size(); i++){
        child[i]=parent1[i];
    }
    
    child[0]=1;
    
    int start = 1;
    for(int i = 1; i<spot; i++){
        
        bool idk = alreadyIn (child, parent2[start]);
        while (alreadyIn (child, parent2[start])){
            start++;
        }
        child[i] = parent2[start];
        start++;
        
    }
    int childSize = g.getPathDistance(child);
    pair<int, vector<int>> sizeAndPath (childSize, child);
    randomRoutes.push_back(sizeAndPath);
    
    
}


bool genetic::alreadyIn (vector<int> child, int n){
    std::vector<int>::iterator it;
    
    it = find (child.begin(), child.end(), n);
    if (it != child.end())
        return true;
    else
        return false;
    
}


void genetic:: mutate(Graph & g){
    int i = randomRoutes.size()-1;
    int index = rand() % i+1;
    int bleh = nodeCount -1;
    int spot1 = rand() % bleh+1;
    int spot2 = rand() % bleh+1;
    
    int temp = randomRoutes[index].second[spot2];
    randomRoutes[index].second[spot2] = randomRoutes[index].second[spot1];
    randomRoutes[index].second[spot1] = temp;
    
    int size = g.getPathDistance(randomRoutes[index].second);
    randomRoutes[index].first = size;
    
}
void genetic::setGoal(int s){
    goal = s;
}

