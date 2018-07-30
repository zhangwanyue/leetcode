//
// Created by vera on 18-7-30.
//
# include<iostream>
# include <vector>

using namespace std;
/**
 * 标准答案的解法：
 * 直接使用两次二分法，第一次找开始的target，第二次找结束的target
 */

class Solution {
    // returns leftmost (or rightmost) index at which `target` should be
    // inserted in sorted array `nums` via binary search.
private:
    int extremeInsertionIndex(vector<int>& nums, int target, bool left) {
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target || (left && target == nums[mid])) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        return lo;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> targetRange = {-1, -1};

        int leftIdx = extremeInsertionIndex(nums, target, true);

        // assert that `leftIdx` is within the array bounds and that `target`
        // is actually in `nums`.
        if (leftIdx == nums.size() || nums[leftIdx] != target) {
            return targetRange;
        }

        targetRange[0] = leftIdx;
        targetRange[1] = extremeInsertionIndex(nums, target, false)-1;

        return targetRange;
    }
};

int main(){
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> vec = (new Solution)->searchRange(nums, target);
    for(int num : vec){
        cout<<num<<" ";
    }
}
