//
// Created by vera on 18-7-21.
//
# include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 使用递归遍历做
 */

class Solution {
public:
    static const vector<vector<char>> MAP;
    vector<string> res;
    string curr;
    size_t len;

    vector<string> letterCombinations(string digits) {
//        len = digits.size();
//        if (len == 0) { return {}; }

        res.clear();
        curr.clear();

        helper(digits, 0);
        return res;
    }

    void helper(const string& digits, size_t pos) {
        if (pos == len) {
            res.push_back(curr);
            return;
        }

        for (auto c : MAP[digits[pos] - '0']) {
            curr.push_back(c);
            helper(digits, pos + 1);
            curr.pop_back();
        }
    }
};

const vector<vector<char>> Solution::MAP = {
        {},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'},
};

//int main(){
//    string digit = "";
//    vector<string> resVec = (new Solution)->letterCombinations(digit);
//    for(string res : resVec){
//        cout<<res<<endl;
//    }
//}