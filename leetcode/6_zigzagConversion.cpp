//
// Created by vera on 18-7-18.
//
# include<iostream>
#include <deque>

using namespace std;
/**
 * 找规律，找循环就可以了
 * 涉及到双端队列初始化
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }else{
            int circular = 2*numRows - 2;
            cout<<circular<<endl;
            deque< deque<char> > pos(circular);
            for(int i=0; i<s.length(); i++){
                int remain = i%circular;
                pos[remain].push_back(s[i]);
            }
            string result;
            for(int j=0; j<numRows; j++){
                while(pos[j].size() > 0){
                    result+=pos[j][0];
                    pos[j].pop_front();
                    int nextJ = circular-j;
                    if(nextJ!=j && nextJ<circular && pos[nextJ].size()>0){
                        result+=pos[nextJ][0];
                        pos[nextJ].pop_front();
                    }
                }
            }
            return result;
        }
    }
};


int main(){
    string s = "012345abcdef";
    int numRows = 2;
    cout<< (new Solution)->convert(s, numRows);
    //双端队列初始化
//    deque< deque<char> > pos(10);
//    pos[1].push_back('a');
//    cout<<pos[1][0]<<endl;
}