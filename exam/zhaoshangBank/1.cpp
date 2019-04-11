//
// Created by vera on 19-4-9.
//
#include <iostream>
#include <vector>

using namespace std;

//从vecs中找是否所有vec都包含target，如果是的话，返回对应的所有costs的和，否则返回-1
int findSumInVecs(vector<vector<int> > vecs, int vecNum, int target, vector<vector<int>> costs){
    int sum = 0;
    bool findFlag;
    for(int i=0; i<vecNum; i++){
        findFlag = false;
        for(int j=0; j<vecs[i].size(); j++){
            if(vecs[i][j] == target){
                sum += costs[i][j];
                findFlag = true;
            }
        }
        if(!findFlag){
            return -1;
        }
    }
    return sum;
}

int findMax(vector<int> vec){
    int max = -1;
    for(int i=0; i<vec.size(); i++){
        if(max==-1 || vec[i]>max){
            max = vec[i];
        }
    }
    return max;
}

int main(){
    int n;
    vector<int> a;
    vector<vector<int>> sizeVec;
    vector<vector<int>> move;
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
        sizeVec.push_back({tmp});
        move.push_back({0});
    }

    int maxNum = findMax(a);

    for(int i=0; i<n; i++){
        int count = 0;
        for(int size=a[i]; size>1; ){
            count++;
            size = size/2;
            sizeVec[i].push_back(size);
            move[i].push_back(count);
        }
        count = 0;
        for(int size=a[i]; size<maxNum;){
            count++;
            size = size*2;
            sizeVec[i].push_back(size);
            move[i].push_back(count);
        }
    }
    long long minSum = -1;

    for(int j=0; j<sizeVec[0].size(); j++){
        int tmpSum = findSumInVecs(sizeVec, n, sizeVec[0][j], move);
        if(minSum==-1 || tmpSum!=-1 && tmpSum<minSum){
            minSum = tmpSum;
        }
    }
    cout<<minSum;
}

