//
// Created by vera on 18-9-26.
//
# include <iostream>
# include <vector>

using namespace std;

/**
 * 将循环从一个点打开，拆成线型的
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0], nums[1]);
        if(nums.size()>2)
            //要第一个，或者不要
            return max(nums[0]+linerRob(nums, 2, nums.size()-2), linerRob(nums, 1, nums.size()-1));
            //要第一个，或者要最后一个，或者都不要
//            return max(linerRob(nums, 1, nums.size()-1), max(nums[0]+linerRob(nums, 2, nums.size()-2), nums[nums.size()-1]+linerRob(nums, 1, nums.size()-3)));
    }
    int linerRob(vector<int>& nums, int start, int end){
        vector<int> res(nums);
        if(start>end)
            return 0;
        if(end-start>=1) {
            res[start + 1] = max(res[start], res[start + 1]);
        }
        for(int i=start+2; i<=end; i++){
            res[i] = max(res[i-2]+res[i], res[i-1]);
        }
        return res[end];
    }
};

int main() {
    vector<int> nums = {2,7,9,3,1}; //11
//    vector<int> nums = {};
//    vector<int> nums = {1,2,3,1}; //4
//    vector<int> nums = {2,1,1,2}; //3
//    vector<int> nums = {2,7,9,3,1}; //11
//    vector<int> nums = {4,1,2,7,5,3,1}; //14
//    vector<int> nums = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5}; //16
//    vector<int> nums = {2, 3, 2}; //3
    cout<<(new Solution)->rob(nums)<<endl;
}