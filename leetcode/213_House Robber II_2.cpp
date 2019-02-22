//
// Created by vera on 18-9-26.
//
# include <iostream>
# include <vector>

using namespace std;
/**
 * 用递归也可以做，但是在leetcode上测试会超时
 * 因为动态规划的时间复杂度和空间复杂度都比递归小的多
 * 动归有记录从前算过的值的功能，递归要重复计算
 * 递归栈也是很占用内存的
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        if (nums.size() > 2)
            //要第一个，或者不要
            return max(nums[0] + recurRob(nums, 2, nums.size() - 2), recurRob(nums, 1, nums.size() - 1));
    }

    int recurRob(vector<int>& nums, int start, int end) {
        if(start>end)
            return 0;
        if(start == end)
            return nums[start];
        return max(nums[start]+recurRob(nums, start+2, end), recurRob(nums, start+1, end));
    }

};

int main() {
//    vector<int> nums = {2,7,9,3,1}; //11
//    vector<int> nums = {};
//    vector<int> nums = {1,2,3,1}; //4
    vector<int> nums = {2,1,1,2}; //3
//    vector<int> nums = {2,7,9,3,1}; //11
//    vector<int> nums = {4,1,2,7,5,3,1}; //14
//    vector<int> nums = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5}; //16
//    vector<int> nums = {2, 3, 2}; //3
    cout<<(new Solution)->rob(nums)<<endl;
}
