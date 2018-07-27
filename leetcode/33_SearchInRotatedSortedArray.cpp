//
// Created by vera on 18-7-27.
//

# include<iostream>
# include <vector>
using namespace std;

/**
 * 先寻找privot点，然后在privot两边分别进行二分查找
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find pivot
        int start = 0, end = nums.size()-1, middle;
        int resLocation;
        if(end<0){
            return -1;
        }
        if(nums[start]<=nums[end]){//没有privot(或者元素小于等于２，此时肯定没有privot)
            return findNum(nums,target,start,end);
        }
        while(start<end-1){
            middle = (start+end)/2;
            if(nums[middle]<nums[start]){//说明privot在这一段中
                end = middle;
            }
            if(nums[middle]>nums[end]){//说明privot在这一段中
                start = middle;
            }
        }//start指向第一个序列的最后一个元素，end指向后一个序列的第一个元素
        if(target<nums[0]){//要在后一个序列找
            resLocation = findNum(nums, target, end, nums.size()-1);
        }else{//要在前一个序列找
            resLocation = findNum(nums, target, 0, start);
        }
        return resLocation;
    }

private:
    int findNum(vector<int>& nums, int target, int start, int end){//二分查找
        int middle;
        while(start<=end){
            middle = (start+end)/2;
            if(nums[middle]<target){
                start = middle+1;
            } else if(nums[middle]>target){
                end = middle-1;
            }else if(nums[middle] == target){
                return middle;
            }
        }
        return -1;
    }
};

//int main(){
////    vector<int> nums = {4,5,6,7,0,1,2};
////    vector<int> nums = {1, 3, 5};
//    vector<int> nums = {1,3};
//    int target = 3;
//    cout<<(new Solution)->search(nums, target);
//}