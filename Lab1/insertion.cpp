//
//  insertion.cpp
//  Lab1
//
//  Created by Blair Saunders on 9/6/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "insertion.h"

#include <iostream>
using namespace std;
void insertion::insertionsort (std::vector<int>&list){
    int left, right, correctSpot, value;
    bool keepChecking;

    //starts at the second value of the array and compare it to the first value
    for(int i = 1; i<list.size(); i++){
        keepChecking = true;
        value = list[i];//the value of focus
        left = i-1;//left index
        right = i;//right index
        correctSpot = i;//the spot the element should be at

        //while we have not hit the beginning of the array and the bool to continue checking is true
        while(left>= 0 && keepChecking == true){
            if(list[left]>list[right]){//the value on the left is greater the value of focus (righter value)
                if(left == 0){//the left value is the beginning of the array
                    keepChecking = false;//we no longer need to continue checking values (because there are no more left to check)
                    correctSpot--;//the correct spot for the value of focus (righter value) is decremented
                }
                else{//the left value is not the beginning of the array
                    left --;
                    correctSpot--;
                }
            }
            else{//the value on the left is not greater than the value of focuse (righter value)
                keepChecking = false;//no longer need to check for this value of focus
            }
        }
        list.insert(list.begin()+correctSpot, value);//inserts the value of focus to the correct spot
        list.erase(list.begin()+i+1);//deletes the value of focus from its original spot
    }

}
