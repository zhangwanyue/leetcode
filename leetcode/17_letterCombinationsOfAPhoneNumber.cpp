//
// Created by vera on 18-7-20.
//
# include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * 当做了一个大数加法来做的
 */

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

vector<string> keyboard = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int digitLen = digits.length();
        vector<int> indexVec(digitLen, 0);
        vector<string> resVec;
        string str = "";
        bool carry = false;
        vector<string>letterVec;
        for(char digit : digits){
            letterVec.push_back(keyboard[digit - '0']);
        }
        while(!indexVec.empty() && indexVec[0]<letterVec[0].size()){
            carry = false;
            for(int i=0; i<digitLen; i++){
                str += letterVec[i][indexVec[i]];
            }
            resVec.push_back(str);
            str = "";
            indexVec[digitLen-1]++;//给indexVec的最后一个元素加一（一共有letters.size()个元素）
            for(int i=digitLen-1; i>=0; i--) {//每次进入这个for循环，就相当于给indexVec的最后一个元素加一，然后前面的元素如果有需要，则依次进位
                string letters = letterVec[i];
                if (carry) {
                    indexVec[i]++;
                }
                carry = false;
                if (i!=0 && indexVec[i] >= letters.size()) {//有点像计算大数加法，考虑怎么进位
                    indexVec[i] = 0;
                    carry = true;
                }
            }
        }
        return resVec;
    }
};

//int main(){
//    string digit = "2";
//    vector<string> resVec = (new Solution)->letterCombinations(digit);
//    for(string res : resVec){
//        cout<<res<<endl;
//    }
//}
