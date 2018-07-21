//
// Created by vera on 18-7-21.
//
# include<iostream>
#include <vector>

using namespace std;

/**
 * 用递归法做的
 * 递归法要注意，直接在传参的位置改变参数。
 * 举例来说，不要写成：
 * res = res + '(';
 * find(res, leftPos+1, rightPos, n);
 * 否则在find之后还要res.pop_back();
 * 要直接写成：
 * find(res+'(', leftPos+1, rightPos, n);
 */
class Solution {
public:
    vector<string> resVec;

    vector<string> generateParenthesis(int n) {
        find("", 0, 0, n);
        return resVec;
    }

private:
    void find(string res, int leftPos, int rightPos, int n){
        if(leftPos == n && rightPos ==n){
            resVec.push_back(res);
            return;
        }

        if(leftPos<n){
            //不要写成
            //res = res + '('
            //否则在find之后还要res.pop_back()
            find(res+'(', leftPos+1, rightPos, n);
        }

        if(rightPos<n && rightPos<leftPos){
            find(res=')', leftPos, rightPos+1, n);
        }

    }
};

int main(){
    int n = 3;
    vector<string> resVec = (new Solution)->generateParenthesis(n);
    for(string res : resVec){
        cout<<res<<endl;
    }
}
