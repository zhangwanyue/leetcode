//
// Created by vera on 19-4-14.
//

#include <iostream>
#include <vector>
using namespace std;

bool testMinPower(int minPower, vector<int>& vec){
    for(int i=0; i<vec.size(); i++){
        minPower = minPower - (vec[i]-minPower);
        if(minPower<0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int> h;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        h.push_back(tmp);
    }
    int minPower = 1;
    bool find = false;
    while(!find){
        if(testMinPower(minPower, h)){
            cout<<minPower;
            find = true;
        }else{
            minPower++;
        }
    }
}