//
// Created by vera on 19-8-10.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    long long min = abs(vec[1]-vec[0]);
    long long temp;
    long long a=vec[0], b=vec[1];
    for(int i=1; i<n; i++){
        temp = abs(vec[i-1]-vec[i]);
        if(temp < min){
            a = vec[i-1];
            b = vec[i];
            min = temp;
        }
    }
    cout<<a<<" "<<b;
}
