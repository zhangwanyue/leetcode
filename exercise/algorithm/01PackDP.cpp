//
// Created by vera on 19-6-19.
//

#include <iostream>
#include <vector>

using namespace std;

const int NUM = 5;
const int TOTALCAPACITY = 9;

// (size, value)
vector<pair<int, int> > items = {make_pair(2, 3), make_pair(1, 2), make_pair(3, 4), make_pair(2, 2), make_pair(3, 3)};

// 表示将前n件物品（截止到第n个）放入一个容量为v的背包可以获得的最大价值
int rec(int n, int capacity){
    // dp数组
    int dp[NUM+1][TOTALCAPACITY+1] = {}; // 全部初始化为0
    for(int i=1; i<=n; i++){
        for(int j=1; j<=capacity; j++){
            if(j-items[i-1].first < 0){ // 放不下第i个物件
                dp[i][j] = dp[i-1][j];
            }else{
                // 计算放第i个物件或者不放第i个物件的最大值
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i-1].first] + items[i-1].second);
            }
        }
    }
    return dp[n][capacity];
}

//int rec(int n, int capacity){
//    // dp数组
//    int dp[NUM+1][TOTALCAPACITY+1] = {}; // 全部初始化为0
//    for(int i=0; i<n; i++){
//        for(int j=0; j<=capacity; j++){
//            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
//            if(j+items[i].first <= TOTALCAPACITY){
//                dp[i+1][j+items[i].first] = max(dp[i+1][j+items[i].first], dp[i][j] + items[i].second);
//            }
//        }
//    }
//    return dp[n][capacity];
//}

int main(){
    cout<<rec(NUM, TOTALCAPACITY)<<endl;
}