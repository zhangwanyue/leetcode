//
// Created by vera on 19-8-10.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-6;

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
        for(int j=i+1; j<n; j++){
            if((long double)vec[j]*0.9-(long double)vec[i]<eps){
                count++;
            }else{
                break;
            }
        }
    }
    cout<<count;
}
