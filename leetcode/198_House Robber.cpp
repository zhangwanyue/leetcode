//
// Created by vera on 18-9-25.
//
# include <iostream>
# include <vector>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        return maxRob(nums, 0);
    }
    int maxRob(vector<int>& nums, int start){
        if(start==nums.size()-1){
            return nums[start];
        } else if(start+1<nums.size()) {
            int max1 = nums[start] + maxRob(nums, start + 2);
            int max2 = nums[start + 1] + maxRob(nums, start + 3);
            return max1 > max2 ? max1 : max2;
        } else{
            return 0;
        }
    }
};

int main(){
    vector<int> nums = {2,7,9,3,1};
    cout<<(new Solution)->rob(nums);
}
