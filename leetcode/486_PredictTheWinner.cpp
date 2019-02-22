//
// Created by vera on 18-8-9.
//
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

/**
 * 回溯法做
 * Min-Max algorithm
 */
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        return backtrace(nums, start, end, 0, 0, true);
    }
    bool backtrace(vector<int>& nums, int start, int end, int play1, int play2, bool turnToPlay1){
        if(start > end){
            if(play1 >= play2){
                return true;
            } else{
                return false;
            }
        }else{
            if(turnToPlay1){
                //只要play1找到一种可以赢的方式就可以
                return backtrace(nums, start+1, end, play1+nums[start], play2, false) ||
                        backtrace(nums, start, end-1, play1+nums[end], play2, false);
            }else{
                //play2是一个机智的挑战者，必须保证无论他选择哪种情况play1都可以赢
                return backtrace(nums, start+1, end, play1, play2+nums[start], true) &&
                       backtrace(nums, start, end-1, play1, play2+nums[end], true);
            }
        }
    }
};

//int main(){
//    vector<int> nums = {1, 5, 2};
////    vector<int> nums = {1, 5, 233, 7};
//    cout<<(new Solution)->PredictTheWinner(nums)<<endl;
//}
