//
// Created by vera on 18-7-25.
//
# include<iostream>
# include<vector>
#include <algorithm>

using namespace std;

/**
 * 做这道题动笔要试一试，就能总结出方法了
 * 比如：1432，从最后一个数依次与前一个数比较，看是否小于前一个数
 * 3>2, 4>3,但是1<4，于是定位到1这个数字（index=0）
 * 然后让1后面的数字sort排序，变成1234
 * 然后swap函数就从2开始依次寻找1后面的数中大于1的，找到之后和1交换，所以这里再交换1和2，变成2134
 *
 * 先找到从后向前数，第一个降序的位置，把此位置后面的翻转。再把这个降序数字和后面第一个比它大的位置交换即可。
 */

static int x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = 0;
        int i = 0;
        bool flag = false;
        for(i=nums.size()-1; i>0; i--){
            if(nums[i]>nums[i-1]){//寻找低位数字大于高位的
                index = i-1;
                sort(nums.begin()+i, nums.end());//升序排列
                swap(nums, index, i, nums.size()-1);
                flag = true;
                break;
            }
        }
        if(!flag){
            sort(nums.begin(), nums.end());
        }
    }

private:
    void swap(vector<int>& nums, int index, int i, int j){
        //nums[i]到nums[j]已经从小到大排好了顺序
        //寻找nums[i]到nums[j]中第一个大于nums[index]的数字，并和nums[index]交换
        int temp;
        for(int k = i; k<=j; k++){
            if(nums[k]>nums[index]){
                temp = nums[k];
                nums[k] = nums[index];
                nums[index] = temp;
                break;
            }
        }
    }
};

//int main(){
//    vector<int> nums = {1, 2, 3};
//    (new Solution)->nextPermutation(nums);
//    for(int num : nums){
//        cout<<num<<" ";
//    }
//}