//
// Created by vera on 18-7-29.
//
# include<iostream>
# include <vector>
# include<map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> resVec;
        vector<int> current;
        map<int, int> remain;
        for(int num:nums){
            if(remain.find(num)!=remain.end()){
                remain[num] += 1;
            }else{
                remain[num] = 1;
            }
        }
        backtracking(nums.size(), resVec, remain, current);
        return resVec;
    }

private:
    void backtracking(int numSize, vector<vector<int>>& resVec, map<int, int> remain, vector<int> current){
        if(current.size()==numSize){
            resVec.push_back(current);
            return;
        } else{
            for(map<int, int>::iterator mapIter = remain.begin();mapIter!=remain.end();mapIter++){
                if(mapIter->second>0) {
                    current.push_back(mapIter->first);
                    mapIter->second--;
                    backtracking(numSize, resVec, remain, current);
                    current.pop_back();
                    mapIter->second++;
                }
            }
        }
    }
};

//int main(){
//    vector<int> nums = {1, 1, 2};
//    vector<vector<int>> resVec = (new Solution)->permuteUnique(nums);
//    for(vector<int> res : resVec){
//        for(int num : res){
//            cout<<num<<" ";
//        }
//        cout<<endl;
//    }
//}