//
// Created by vera on 19-9-15.
//
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    int num;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    cin>>num;

    int result=0;
    sort(vec.begin(), vec.end());
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                if(vec[i]+vec[j]+vec[k]<num){
                    result++;
                }else{
                    break;
                }
            }
        }
    }
    cout<<result;
    return 0;
}

