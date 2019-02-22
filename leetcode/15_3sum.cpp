//
// Created by vera on 18-7-20.
//
# include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 思路是:先sort排序，然后对每一个vector中的nums=a，寻找后面的全部元素能不能有两个（b, c)加起来正好满足a+b+c = 0
 * 怎么找b,c这两个元素呢？可以设置一个双指针（p,q），分别指向头尾，如果加起来大于零，尾指针前移，如果加起来小于零，头指针后移。
 * 注意重复的数字要跳过
 * 找到这样的一组b,c之后，还是要继续寻找其他可能的b,c，找到一个合适的终止条件（p<q）
 */

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for (int i=0; i< nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int t = -nums[i];
            int j = i+1, k = nums.size()-1;
            while(j < k) {
                int total = nums[j] + nums[k];
                if (total>t) k--;
                else if (total<t) j++;
                else {
                    ans.push_back({-t, nums[j], nums[k] });
                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};

//int main(){
////    vector<int> nums = {-1, 0, 1, 2, -1, -4};
////    vector<int> nums = {};
////    vector<int> nums = {-2, 0, 1, 1, 2};
//    vector<int> nums = {-1,2};
//    vector< vector<int> > resultVec = (new Solution)->threeSum(nums);
//    for(vector<int> oneResult : resultVec){
//        for(int num:oneResult){
//            cout<<num<<" ";
//        }
//        cout<<endl;
//    }
//
//}