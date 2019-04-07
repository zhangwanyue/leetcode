//
// Created by vera on 19-4-5.
//
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<int> vec;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }
//    int m=20, n=4;
//    vector<int> vec = {1, 2, 5, 10};
    sort(vec.begin(), vec.end());
    int sum = 0;
    bool flag = true;
    for(int i=1; i<=m && flag;){
        flag = false;
        for(int j=n-1; j>=0; j--){
            if(vec[j]<=i){
                sum++;
                flag = true;
                i+=vec[j];
                break;
            }
        }
    }
    if(flag){
        cout<<sum;
    }else{
        cout<<-1;
    }
}