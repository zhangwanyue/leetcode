//
// Created by vera on 19-4-9.
//

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> vec, int target){
    int left = 0;
    int right = vec.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(vec[mid]==target){
            return mid;
        }
        if(vec[mid]<target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> vec = {3, 5, 1, 6, 7, 2, 5, 5};
    cout<<binarySearch(vec, 5);
}


