//
//  bubble.cpp
//  Lab1
//
//  Created by Blair Saunders on 8/26/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "bubble.h"
#include <iostream>
using namespace std;

//repeatedly switching the neighboring elements that are in the wrong order
void bubble::bubblesort (vector<int>& list){
    int first;
    for (int i = 0; i<list.size(); i++){
        for(int j = 0; j<list.size()-i-1; j++){
            if(list[j]>list[j+1]){
                first = list[j];
                list[j] = list[j+1];
                list[j+1]= first;
            }
        }
    }

}
