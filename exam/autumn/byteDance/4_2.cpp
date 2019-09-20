//
// Created by vera on 19-9-15.
//
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

//x>=现价和-优惠和


bool cmp(pair<int, long long> a, pair<int, long long> b){
    return a.first<b.first; //从小到大
}

// 表示将前n件物品（截止到第n个）放入一个容量为v的背包可以获得的最大价值
long long rec(int n, int capacity, vector<pair<int, long long>>& gameVec){
    // dp数组
    long long dp[n+1][INTMAX_MAX];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<capacity+1; j++){
            dp[i][j]=0;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=capacity; j++){
            if(j-gameVec[i-1].first < 0){ // 放不下第i个物件
                dp[i][j] = dp[i-1][j];
            }else{
                // 计算放第i个物件或者不放第i个物件的最大值
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-gameVec[i-1].first] + gameVec[i-1].second);
            }
        }
    }
    return dp[n][capacity];
}



int main(){
    int n, x;
    cin>>n>>x;
    vector<pair<int, long long>> gameVec(n);
    int tempOrginMoney, tempNowMoney;
    long long tempHappy;
    for(int i=0; i<n; i++){
        cin>>tempOrginMoney>>tempNowMoney>>tempHappy;
        gameVec[i] = make_pair(2*tempNowMoney-tempOrginMoney, tempHappy); //现价-优惠(nowMoney-(originMoney-nowMoney))=(2nowMoney-originMoney)
    }
    sort(gameVec.begin(), gameVec.end(), cmp);
    cout<<rec(n, x, gameVec);
    return 0;
}
