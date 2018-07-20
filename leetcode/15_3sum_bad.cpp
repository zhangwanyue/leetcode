//
// Created by vera on 18-7-19.
//
# include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> resultVec;
        sort(nums.begin(), nums.end());//sort的end应该指向最后一个元素的下一个位置
        int needNum = 0;
        int numSize = static_cast<int>(nums.size());
        for(int i=0; numSize>2 && i<numSize-2;){
            needNum = 0-nums[i];
            for(int j=i+1, h=numSize-1; j<h&&j<numSize-1; ){
                if(nums[j]+nums[h]>needNum){
                    h--;
                }else if(nums[j]+nums[h]<needNum){
                    j++;
                }else{
                    vector<int> oneResult = {nums[i], nums[j], nums[h]};
                    resultVec.push_back(oneResult);
                    jumpBackToDiffOne(j, h, nums);
                    jumpFrontToDiffOne(h, j, nums);
                }
            }
            jumpBackToDiffOne(i, numSize-2, nums);
        }
        return resultVec;
    }

private:
    //向后跳转直到遇到不同的值
    void jumpBackToDiffOne(int& i, int end, const vector<int>& nums){
        for(int tempi=i, num=nums[i];tempi<end;){
            if(nums[tempi]==num){
                i++;
                tempi++;
            } else{
                return;
            }
        }
    }
    //向前跳转直到遇到不同的值
    void jumpFrontToDiffOne(int& i, int end, const vector<int>& nums){
        for(int tempi=i, num=nums[i];tempi>end;){
            if(nums[tempi]==num){
                i--;
                tempi--;
            } else{
                return;
            }
        }
    }

};

//int main(){
////    vector<int> nums = {-1, 0, 1, 2, -1, -4};
////    vector<int> nums = {};
////    vector<int> nums = {-2, 0, 1, 1, 2};
//    vector<int> nums = {0, 0, 0};
//    vector< vector<int> > resultVec = (new Solution)->threeSum(nums);
//    for(vector<int> oneResult : resultVec){
//        for(int num:oneResult){
//            cout<<num<<" ";
//        }
//        cout<<endl;
//    }
//
//}
