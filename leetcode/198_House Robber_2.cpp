//
// Created by vera on 18-9-25.
//
# include <iostream>
# include <vector>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()>=2)
            nums[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++){
            nums[i] = max(nums[i-2]+nums[i], nums[i-1]);
        }
        return nums[nums.size()-1];
    }
};

int main(){
//    vector<int> nums = {2,7,9,3,1};
//    vector<int> nums = {};
//    vector<int> nums = {1,2,3,1};
    vector<int> nums = {2,1,1,2};
    cout<<(new Solution)->rob(nums);
}
