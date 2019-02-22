//
// Created by vera on 18-8-12.
//
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

/**
 * 动态规划方法做
 * Min-Max algorithm
 * dp[start][end]中存的是：当前竞争者第一个选的前提下，现有从start到end的这些元素，他的最大净胜量是多少
 */

class Solution {
public:
    bool PredictTheWinner(vector<int> &nums) {
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), 0));
//        for(int i=0; i<nums.size(); i++){
//            dp[i][i] = nums[i];
//        }
        for(int end=1; end<nums.size(); end++){
            for(int start=end-1; start>=0; start--){
                int a = nums[start] - dp[start+1][end];
                int b = nums[end] - dp[start][end-1];
                dp[start][end] = max(a, b);
            }
        }
        return dp[0][nums.size()-1]>=0;
    }

};


//int main(){
////    vector<int> nums = {1, 5, 2};
////    vector<int> nums = {1, 5, 233, 7};
//    vector<int> nums = {0};
//    cout<<(new Solution)->PredictTheWinner(nums)<<endl;
//}