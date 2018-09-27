//
//  merge.cpp
//  Lab1
//
//  Created by Blair Saunders on 9/3/18.
//  Copyright © 2018 Blair Saunders. All rights reserved.
//

#include "Merge.h"
#include <iostream>
using namespace std;
void Merge::mergesort (vector<int>& int_list){
    divide(int_list, 0, int_list.size()-1);
}

void Merge:: divide (std::vector<int>&list, int first_index, int last_index){
    int middle_index;
    if(first_index != last_index){
        middle_index = (first_index+last_index)/2;//middle point of the vector
        divide(list, first_index, middle_index);//call the divide function on the first half of the vector
        divide(list, middle_index+1, last_index);//call the divide function on the second half of the vector
        join(list, first_index, middle_index, last_index);//join the two sorted halves, sorting once again
    }

}

void Merge:: join (std::vector<int>&list, int first_index, int middle_index, int last_index){
    int left_start = first_index;//the start of the first half
    int left_end = middle_index;//the end of the first half
    int right_start = middle_index+1;//the start of the second half
    int right_end = last_index; //the end of the second half
    int value;//this will hold the elements at a specific index
    while(left_start <= left_end && right_start <= right_end){//each half begins at their first index
        if(list[left_start] <= list[right_start]){//checks if the specific value the loop is on in the first half is less than or equal to the specific value the loop is on in the  second half
            left_start++;//the loop moves on with no changes made
        }
        else{//indicating the specific value the loop is on in the first half is greater than the specific value the loop is on in the  second half
            value = list[right_start];//saves the value from the second half
            list.insert(list.begin()+left_start, value);//inserts it before the value from the first half
            list.erase(list.begin()+right_start+1);//makes sure to erase the value from the second half
            left_start++;
            left_end++;
            right_start++;
        }
    }
}
