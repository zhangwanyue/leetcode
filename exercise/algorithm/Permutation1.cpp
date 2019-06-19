//
// Created by vera on 19-6-19.
//

#include <iostream>

using namespace std;

const int MAX_N = 10;

bool used[MAX_N] = {false}; // all elements 0
int perm[MAX_N] = {0}; // all elements 0

// 生成 {0, 1, 2, 3, 4, ..., n-1} 的 n! 种排列

void permutation1(int pos, int n){
    if(pos == n){
        for(int i=0; i<4; i++){
            cout<<perm[i]<<" ";
        }
        cout<<endl;
        // 对perm进行的操作
        return;
    }
    for(int i=0; i<n; i++){
        if(!used[i]){
            perm[pos] = i;
            used[i] = true; // i已经被使用了，所以把标志设置为true
            permutation1(pos+1, n);
            used[i] = false; // 返回之后把标志复位
        }
    }
    return;
}


int main(){
    permutation1(0, 4);
}