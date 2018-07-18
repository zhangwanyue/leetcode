//
// Created by vera on 18-7-18.
//
# include<iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        bool path[len][len] = {false};
        int start=0, end=0;
        int maxlen = 0;
        for(int i=len-1; i>=0; i--){
            for(int j=i; j<len; j++){
                if((j-i<=2 || path[i+1][j-1]==1) && s[i] == s[j]){
                    path[i][j]=true;
                    if(j-i+1 > maxlen){
                        start = i;
                        end = j;
                        maxlen = j-i+1;
                    }
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};

int main(){
    string s = "aabbcbb";
    cout<< (new Solution)->longestPalindrome(s);
}


