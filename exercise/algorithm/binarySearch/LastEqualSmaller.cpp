//
// Created by vera on 19-4-7.
//
#include <iostream>
#include <vector>

using namespace std;

//查找最后一个等于小于key的元素

int findLastEqualSmaller(vector<int> vec, int key){
    int left = 0;
    int right = vec.size() -1;
    while(left <= right){
        int mid = (left + right)/2;
        if(vec[mid] > key){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return right;
}

int main(){
    vector<int> vec = {4,5};
    int key = 3;
    cout<<findLastEqualSmaller(vec, key);
}
