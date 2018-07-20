//
// Created by vera on 18-7-20.
//
# include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for (int i=0; i< nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int t = -nums[i];
            int j = i+1, k = nums.size()-1;
            while(j < k) {
                int total = nums[j] + nums[k];
                if (total>t) k--;
                else if (total<t) j++;
                else {
                    ans.push_back({-t, nums[j], nums[k] });
                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};

//int main(){
////    vector<int> nums = {-1, 0, 1, 2, -1, -4};
////    vector<int> nums = {};
////    vector<int> nums = {-2, 0, 1, 1, 2};
//    vector<int> nums = {-1,2};
//    vector< vector<int> > resultVec = (new Solution)->threeSum(nums);
//    for(vector<int> oneResult : resultVec){
//        for(int num:oneResult){
//            cout<<num<<" ";
//        }
//        cout<<endl;
//    }
//
//}