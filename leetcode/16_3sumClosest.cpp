//
// Created by vera on 18-7-20.
//

//
// Created by vera on 18-7-20.
//
# include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 和3sum的解法类似，也是要设置头尾指针
 * 这个不用寻找a+b+c = 0,而是找abs(target-a-b-c)最小的，记录这个最小值，每次计算中进行比较并更新最小值
 * 可以不用考虑跳过重复元素
 * 如果最小值等于零了，就可以直接返回不用再寻找了，否则要遍历完全部的值
 */
static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int tempSum;
        int closestSum;
        int minGap;
        int tempGap;
        vector<int> closest;
        for (int i=0; i< nums.size(); i++) {
            int j = i+1, k = nums.size()-1;
            while(j < k) {
                tempSum = nums[i] + nums[j] + nums[k];
                tempGap = abs(target-tempSum);
                if(closest.empty() || tempGap < minGap) {
                    minGap = tempGap;
                    closestSum = tempSum;
                    closest = {nums[i], nums[j], nums[k]};
                }
                if (tempSum>target) k--;
                else if (tempSum<target) j++;
                else if (tempSum==target) return tempSum;
            }
        }
        return closestSum;
    }
};

//int main(){
////    vector<int> nums = {-1, 0, 1, 2, -1, -4};
////    vector<int> nums = {};
////    vector<int> nums = {-2, 0, 1, 1, 2};
////    vector<int> nums = {0, 0, 0};
////    vector<int> nums = {-1, 2, 1, -4};
////    vector<int> nums = {-1, 2, 1, -4};
////    vector<int> nums = {1, 1, 1, 1};
//    vector<int> nums = {0, 2, 1, -3};
//    int target = 1;
//    cout<< (new Solution)->threeSumClosest(nums, target)<<endl;
//}