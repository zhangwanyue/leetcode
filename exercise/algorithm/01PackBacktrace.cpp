//
// Created by vera on 19-6-19.
//
#include <iostream>
#include <vector>

using namespace std;

const int NUM = 5;
const int TOTALCAPACITY = 9;

// 记忆数组（使用了记忆数组之后，就相当于使用dp进行计算了）
int dp[NUM+1][TOTALCAPACITY+1] = {}; // 全部初始化为0

// (size, value)
vector<pair<int, int> > items = {make_pair(2, 3), make_pair(1, 2), make_pair(3, 4), make_pair(2, 2), make_pair(3, 3)};

// 统计递归调用次数
int count = 0;

// 表示将前n件物品（截止到第n个）放入一个容量为v的背包可以获得的最大价值
int rec(int n, int remainCapacity){
    count++;

    if(n==0){
        return 0;
    }

//    if(dp[i][remainCapacity] > 0){ // 如果该结果已经计算过了，那么就直接使用之前计算的结果，不再次计算了
//        return dp[i][remainCapacity];
//    }

    if(remainCapacity-items[n-1].first < 0){ // 放不下第n个物件
        return rec(n-1, remainCapacity);
    }

    // 计算放第n个物件或者不放第n个物件的最大值
    dp[n][remainCapacity] = max(rec(n-1, remainCapacity), rec(n-1, remainCapacity-items[n-1].first) + items[n-1].second);
    return dp[n][remainCapacity];
}


int main(){
    cout<<rec(NUM, TOTALCAPACITY)<<endl;
    cout<<count<<endl; // 可见，使用记忆数组，可以大大减少递归调用次数
    // 使用记忆数组的时间复杂度为(NUM*TOTALCAPACITY)，不使用记忆数组的时间复杂度为(2^NUM)
}