//
// Created by vera on 18-7-27.
//
# include<iostream>
# include <vector>
#include <algorithm>

using namespace std;

/**
 * 一道回溯法的题目
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 注意candidates不是有序的，要先排序处理
        sort(candidates.begin(), candidates.end());
        // 用以记录答案和当前方案
        vector<vector<int>> ans;
        vector<int> current;
        // 开始回溯搜索
        backtracking(ans, candidates, current, 0, target);
        // 返回答案
        return ans;
    }

    void backtracking(vector<vector<int>>& ans, vector<int>& candidates, vector<int> current, int last_use, int rest_target) {
        // 当rest_target等于0时，说明已经找到了一组合法的方案
        if (rest_target == 0) {
            // 故将其加入到答案当中
            ans.push_back(current);
            return;
        }else if(rest_target < 0){
            return;
        }
        // 否则就枚举下一个加入到current中的数，在枚举中注意2个条件
        // i >= last_use，保证current是非递减的
        // candidates[i] <= rest_target，保证rest_target不小于0
        for (int i = last_use; i < candidates.size() && candidates[i] <= rest_target; i++) {
            // 放入current中
            current.push_back(candidates[i]);
            // 继续搜索下一个数字
            backtracking(ans, candidates, current, i, rest_target - candidates[i]);
            // 回溯处理
            current.pop_back();
        }
    }
};

//int main(){
//    vector<int> candidates = {2,3,5};
//    int target = 8;
//    vector<vector<int>> resVec = (new Solution)->combinationSum(candidates, target);
//    for(vector<int> res:resVec){
//        for(int num: res){
//            cout<<num<<" ";
//        }
//        cout<<endl;
//    }
//}