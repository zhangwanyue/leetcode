//
// Created by vera on 19-6-19.
//

#include <iostream>
using namespace std;

const int N=4, M=4;

////第一种题目：hela和heba的最长公共子序列是hea
//int solve(char s[N], char t[M]){
//    int dp[N+1][M+1] = {}; //dp[i][j]的定义是：截止到s[i]和t[j]的最长公共子序列
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//           if(s[i] == t[j]){
//               dp[i+1][j+1] = dp[i][j] + 1;
//           } else{
//               dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
//           }
//        }
//    }
//    return dp[N][M];
//}

//第二种题目：求最长连续公共子序列，hela和heba的最长连续公共子序列是he
int solve(char s[N], char t[M]){
    int dp[N+1][M+1] = {}; //dp[i][j]的定义是：以s[i]或t[j]（s[i]!=t[j]时dp[i][j]=0）结尾的最长公共子序列
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            } else{
                dp[i+1][j+1] = 0;
            }
        }
    }
    int max=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(dp[i][j]>max){
                max = dp[i][j];
            }
        }
    }
    return max;
}

int main(){
    char s[N] = {'h', 'e', 'l', 'a'};
    char t[M] = {'h', 'e', 'b', 'a'};
    cout<<solve(s, t);
}
