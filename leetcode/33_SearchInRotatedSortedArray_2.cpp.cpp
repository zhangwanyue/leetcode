//
// Created by vera on 18-7-27.
//
# include<iostream>
# include <vector>
using namespace std;

/**
 * 直接进行二分查找，因为最多有一个privot点
 * 所以二分查找的时候，一定有一边是有序的（privot不在这一边）
 * 则二分查找的时候就判断target在不在有序的那一边，否则就在另一边
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(target == nums[m])
                return m;
            if(nums[m]<nums[r])//说明privot不在右边（也可能不存在privot），所以右边是有序的
            {
                if(target>nums[m] && target<=nums[r])//则右边是有序的，判断是否在右边
                    l = m+1;
                else//否则就在左边
                    r = m-1;
            } else {//说明privot在右边，所以左边是有序的
                if(target>=nums[l] && target<nums[m])//则左边是有序的，判断是否在左边
                    r = m-1;
                else//否则就在右边
                    l = m+1;
            }
        }
        return -1;
    }
};

int main(){
//    vector<int> nums = {4,5,6,7,0,1,2};
//    vector<int> nums = {1, 3, 5};
    vector<int> nums = {1,3};
    int target = 3;
    cout<<(new Solution)->search(nums, target);
}