//
// Created by vera on 18-7-30.
//

# include<iostream>
# include <vector>
# include <algorithm>

using namespace std;
/**
 * 这个解题思路太暴力了：
 * 先二分法找到nums中的一个target值
 * 然后从这个位置开始先向后向搜索，寻找开始和结束位置
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, mid;
        int pos = -1;
        int startPos, endPos;
        int tmpStart, tmpEnd;
        while(start<=end){
            mid = (start+end)/2;
            if(nums[mid]==target){
                pos = mid;
                tmpStart = start;
                tmpEnd = end;
                break;
            }else if(nums[mid]>target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        if(pos!=-1){
            for(int i=pos; i<=tmpEnd; i++){
                if((i+1)>nums.size()-1 || nums[i]<nums[i+1]){
                    endPos = i;
                    break;
                }
            }
            for(int i=pos; i>=tmpStart; i--){
                if((i-1)<0 || nums[i-1]<nums[i]){
                    startPos = i;
                    break;
                }
            }
            return {startPos, endPos};
        }else{
            return {-1, -1};
        }

    }
};

//int main(){
//    vector<int> nums = {5, 7, 7, 8, 8, 10};
//    int target = 8;
//    vector<int> vec = (new Solution)->searchRange(nums, target);
//    for(int num : vec){
//        cout<<num<<" ";
//    }
//}