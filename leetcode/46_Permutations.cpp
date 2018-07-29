//
// Created by vera on 18-7-27.
//
# include<iostream>
# include <vector>
#include <algorithm>
using namespace std;

/**
 * 这是一道回溯法的题目
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> resVec;
        vector<int> current;
        vector<int> remain(nums.size(), 0);
        backtracking(nums, resVec, remain, current);
        return resVec;
    }

private:
    void backtracking(vector<int>& nums, vector<vector<int>>& resVec, vector<int> remain, vector<int> current){
        if((current.size()==nums.size())){
//        if(allTried(remain)){//两种判断方法都可以
            resVec.push_back(current);
            return;
        } else{
            for(int i=0; i<remain.size(); i++){
                if(remain[i]!=-1) {
                    current.push_back(nums[i]);
                    remain[i] = -1;
                    backtracking(nums, resVec, remain, current);
                    current.pop_back();
                    remain[i] = 0;
                }
            }
        }
    }

    bool allTried(vector<int>& remain){
        for(int num : remain){
            if(num!=-1){
                return false;
            }
        }
        return true;
    }
};

//int main(){
//    vector<int> nums = {1, 2, 3};
//    vector<vector<int>> resVec = (new Solution)->permute(nums);
//    for(vector<int> res : resVec){
//        for(int num : res){
//            cout<<num<<" ";
//        }
//        cout<<endl;
//    }
//}