#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); ++i) {
            if (lookup.count(target - nums[i])) {
                return {lookup[target - nums[i]], i};
            }
            lookup[nums[i]] = i;
        }
        return {};
    }
};

//int main() {
//    Solution mySolution;
//    vector<int> vector1 = {2, 7, 11, 15};
//    int target = 9;
//    vector<int> vector2 =  mySolution.twoSum(vector1, target);
//    for(int i : vector2){
//        cout<<i<< " ";
//    }
//    return 0;
//}