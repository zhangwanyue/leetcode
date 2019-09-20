//
// Created by vera on 19-8-10.
//

//
// Created by vera on 19-8-10.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-6;

//查找最后一个等于小于key的元素
int findLastEqualSmaller(vector<long long>& vec,int begin, int end, long double key){
    int left = begin;
    int right = end;
    while(left <= right){
        int mid = (left + right)/2;
        if((long double)vec[mid] - key>eps){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return right;
}

int main(){
    int n;
    cin>>n;
    vector<long long> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    sort(vec.begin(), vec.end());
    int count = 0;
    for(int i=0; i<n; i++){
        int find = findLastEqualSmaller(vec, i, vec.size()-1, (long double)vec[i]*0.9);
        count += find-i;
    }
    cout<<count;
}
