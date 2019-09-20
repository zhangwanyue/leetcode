//
// Created by vera on 19-8-3.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool can(vector<int> vec){
    int size = vec.size();
    sort(vec.begin(), vec.end());
    vector<int> vec2(size);
    int left=size/2+1, right=size/2-1;
    vec2[size/2]=vec[size-1];
    for(int i=size-2; i>=0;){
        if(left<size){
            vec2[left]=vec[i];
            i--;
        }
        if(right>=0 && i>=0){
            vec2[right]=vec[i];
            i--;
        }
    }
    for(int i=0; i<size; i++){
        if(vec2[i]>=vec2[((i+1)+size)/size]+vec2[((i-1)+size)/size]){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int j=0; j<n; j++){
            cin>>vec[j];
        }
        if(can(vec))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
