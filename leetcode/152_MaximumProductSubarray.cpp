//
// Created by vera on 18-8-19.
//
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

/**
 * 一维dp（甚至一维空间也不需要，常数空间就可以了）
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        positive.push_back(nums[0]);//其实这样一个数组也是不需要的，只是这样写可读性会高一点。
        negative.push_back(nums[0]);
        int maxProduct = nums[0];
        for(int i=1; i<nums.size(); i++){
            positive.push_back(max(max(positive[i-1]*nums[i], negative[i-1]*nums[i]), nums[i]));//直到位置i的最大正值
            negative.push_back(min(min(positive[i-1]*nums[i], negative[i-1]*nums[i]), nums[i]));
            maxProduct = max(positive[i], maxProduct);
        }
        return maxProduct;
    }
};

int main(){
    vector<int> nums = {1, 0, -1, 2, 3, -5, -2};
    cout<<(new Solution)->maxProduct(nums)<<endl;
}
