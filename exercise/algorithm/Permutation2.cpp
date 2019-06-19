//
// Created by vera on 19-6-19.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10;

int perm[MAX_N] = {}; // all elements 0

void permutation2(int n){
    for(int i=0; i<n; i++){
        perm[i] = i;
    }
    do{
        //需要对perm进行的操作
        for(int i=0; i<4; i++){
            cout<<perm[i]<<" ";
        }
        cout<<endl;
    }while(next_permutation(perm, perm+n));
    return;
}

int main(){
    permutation2(4);
}