//
// Created by vera on 19-3-19.
//
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
    return a>b; //从大到小（如果cmp的返回值是false，就交换a、b的位置）
}
int main(){
    vector<int> vec = {0, 1, 2, 3};
    sort(vec.begin(), vec.end(), cmp);
    for(int i: vec){
        cout<<i<<endl;
    }
}
