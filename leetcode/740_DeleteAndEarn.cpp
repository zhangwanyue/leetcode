//
// Created by vera on 18-7-26.
//
# include<iostream>
# include<vector>
#include <algorithm>

using namespace std;

/**
 * 一道动态规划的题目，一维动态规划
 */
#define MaxNum 10

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(MaxNum+2, 0);
        vector<int> count(MaxNum+1, 0);
        for(int num : nums){
            count[num]++;
        }
        dp[1] = count[1];
        int maxPoint = dp[1];
        for(int num=2; num<MaxNum; num++){
            dp[num] = max(num * count[num] + dp[num - 2], dp[num - 1]);
            maxPoint = max(maxPoint, dp[num]);
        }
        return maxPoint;
    }
};


//int main(){
////   vector<int> nums = {3, 7, 5, 9, 8, 8, 4};
//    vector<int> nums = {3, 4, 2};
//   cout<<(new Solution)->deleteAndEarn(nums);
//}
