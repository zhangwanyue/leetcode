//
// Created by vera on 18-7-22.
//
# include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) {
            ans.push_back("");
        } else {
            for (int c = 0; c < n; ++c)
                for (string left: generateParenthesis(c))
                    for (string right: generateParenthesis(n-1-c)){
                        ans.push_back("(" + left + ")" + right);
                        cout<<left<< " " << right<<" "<<endl;
                    }

        }
        return ans;
    }
};

int main(){
    int n = 3;
    vector<string> resVec = (new Solution)->generateParenthesis(n);
    for(string res : resVec){
        cout<<res<<endl;
    }
}