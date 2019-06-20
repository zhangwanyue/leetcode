//
// Created by vera on 19-6-20.
//

#include <iostream>
using namespace std;

const int INF = INT32_MAX;
const int N = 10;

// 这里dp[i]的定义是：以a[i]结尾的最长上升子序列的长度
int solve1(const int a[N]){
    int dp[N];
    fill(dp, dp+N, INF); // 使用INF初始化dp
    int res = 0;
    for(int i=0; i<N; i++){
        dp[i]=1;
        for(int j=0; j<i; j++){
            if(a[j]<a[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

// 这里dp[i]的定义是：所有长度为i的最长上升子序列中，结尾元素最小的那个子序列的结尾元素
int solve2(const int a[N]){
    int dp[N+1];
    fill(dp, dp+N+1, INF); // 使用INF初始化dp
    dp[1]=a[0];

    for(int i=0; i<N; i++){
        for(int j=1; j<=i; j++){
            if(dp[j]<a[i] && (dp[j+1]>a[i] || dp[j+1]==INF)){ // 这里可以改用二分法（因为dp一定是升序的），复杂度就可以降低
                dp[j+1] = a[i];
            }
        }
    }
    for(int i=N; i>=0; i--){
        if(dp[i]!=INF){
            return i;
        }
    }
}

// 这里dp[i]的定义是：所有长度为i的最长上升子序列中，结尾元素最小的那个子序列的结尾元素
int solve3(const int a[N]){
    int dp[N+1];
    fill(dp, dp+N+1, INF); // 使用INF初始化dp

    for(int i=0; i<N; i++){
        *lower_bound(dp, dp+N, a[i]) = a[i]; // 这里改用二分法(lower_bound(dp, dp+N, a[i])的含义是：查找dp到dp+N中，第一个大于等于a[i]的元素的指针)
    }
    return (lower_bound(dp, dp+N, INF)-dp);

}


int main(){
    int a[N] = {1, 2, 5, 6, 2, 3, 5, 8, 0, 1};
    //LIS={1, 2, 3, 5, 8}
    cout<<solve3(a);
}