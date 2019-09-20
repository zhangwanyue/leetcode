//
// Created by vera on 19-9-19.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    vector<long long> minVec(n+1);
//    vector<long long> minStartPoint(n+1);
    vector<long long> minBeforeSum(n+1);
    minVec[0]=0;
    for(int i=1; i<m+1; i++){
        minVec[i]+=minVec[i-1]+vec[i-1];
//        minStartPoint[i]=0;
        minBeforeSum[i]=0;
    }
    long long min=minVec[m];
    for(int j=m+1; j<minVec.size(); j++){
        minBeforeSum[j] = minBeforeSum[j-1] + vec[j-(m+1)];
        if(minBeforeSum[j]>0){
            minVec[j] = minVec[j-1]-minBeforeSum[j]+vec[j-1];
//            minStartPoint[j] = j-(m+1);
            minBeforeSum[j] = 0;
        }else{
            minVec[j] = minVec[j-1]+vec[j-1];
//            minStartPoint[j] = minStartPoint[j-1];
        }
    }
    for(int i=m; i<minVec.size(); i++){
        if(minVec[i]<min){
            min = minVec[i];
        }
    }
    cout<<min;
}