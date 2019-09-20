//
// Created by vera on 19-9-15.
//

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


//x>现价和-优惠和

struct Game{
    int originMoney;
    int nowMoney;
    int count;//现价-优惠(nowMoney-(originMoney-nowMoney))=(2nowMoney-originMoney)
    long long happy;
    Game(int originMoney, int nowMoney, long long happy){
        this->originMoney = originMoney;
        this->nowMoney = nowMoney;
        this->count = 2*nowMoney-originMoney;
        this->happy = happy;
    }
};


// 表示将前n件物品（截止到第n个）放入一个容量为v的背包可以获得的最大价值
long long rec(int n, int capacity, vector<Game*>& gameVec){
    // dp数组
    long long dp[n+1][capacity+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<capacity+1; j++){
            dp[i][j]=0;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=capacity; j++){
            if(j-gameVec[i-1]->count < 0){ // 放不下第i个物件
                dp[i][j] = dp[i-1][j];
            }else{
                // 计算放第i个物件或者不放第i个物件的最大值
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-gameVec[i-1]->count] + gameVec[i-1]->happy);
            }
        }
    }
    return dp[n][capacity];
}


int main(){
    int n, x;
    cin>>n>>x;
    vector<Game*> gameVec(n);
    int tempOrginMoney, tempNowMoney, tempHappy;
    for(int i=0; i<n; i++){
        cin>>tempOrginMoney>>tempNowMoney>>tempHappy;
        gameVec[i] = new Game(tempOrginMoney, tempNowMoney, tempHappy);
    }
    cout<<rec(n, x, gameVec);
    return 0;
}
