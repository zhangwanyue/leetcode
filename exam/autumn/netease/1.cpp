//
// Created by vera on 19-8-3.
//
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double percent(int currentScore, int totalNum, vector<int> scoreVec){
    int lowerNum=0;
    for(int i=0; i<totalNum; i++){
        if(scoreVec[i]<=currentScore){
            lowerNum++;
        }
    }
    double result = (((double)lowerNum-1)*100)/(double)totalNum;
    return result;
}

int main(){
    cout.setf(ios::fixed);
    int n, q;
    cin>>n;
    vector<int> score(n);
    for(int i=0; i<n; i++){
        cin>>score[i];
    }
    cin>>q;
    int x;
    for(int j=0; j<q; j++){
        cin>>x;
        cout<<setprecision(6)<<percent(score[x-1], n, score)<<endl;
    }
}
