//
// Created by vera on 19-8-10.
//
#include <iostream>
#include <vector>
using namespace std;

//vector<int> top;
//
//void findTop(vector<long long>& vec){
//    long long max = 0;
//    for(int i=0; i<vec.size(); i++){
//        if(vec[i]>max){
//            max = vec[i];
//        }
//    }
//    for(int i=0; i<vec.size(); i++){
//        if(vec[i] == max){
//            top.push_back(i);
//        }
//    }
//    return;
//}

long long countIncrease(vector<long long> vec, int topLocation){
    long long count=0;
    long long tempMax=vec[0];
    for(int i=1; i<=topLocation; i++){
        if(vec[i]<=tempMax){
            count += tempMax+1-vec[i];
            tempMax += 1;
            vec[i] = tempMax;
        }else{
            tempMax = vec[i];
        }
    }
    tempMax=vec[vec.size()-1];
    for(int i=vec.size()-2; i>=topLocation; i--){
        if(vec[i]<=tempMax){
            count += tempMax+1-vec[i];
            tempMax += 1;
            vec[i] = tempMax;
        }else{
            tempMax = vec[i];
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<long long> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
//    findTop(vec);
    long long minCount=INT64_MAX;
    for(int t=0; t<vec.size(); t++){
        long long tempMinCount = countIncrease(vec, t);
        if(tempMinCount<minCount){
            minCount = tempMinCount;
        }
    }
    cout<<minCount;
}