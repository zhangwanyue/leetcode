//
// Created by vera on 18-8-12.
//
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

/**
 * string存的是当前num转成的bits
 * 每一轮都是上一轮加１，然后计算每位的变化
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        string str = "0";
        int count = 0;
        res.push_back(count);
        for(int i=1; i<=num; i++){
            bool carry = false;
            //这一轮的count是利用上一轮的count，计算变化了多少位
            for(int j = str.length()-1; j>=0; j--){
                int temp = (str[j]-'0') + 1; //在上一轮的基础上加１(temp其实只有1和2两种结果)
                carry = (temp/2)==1;
                str[j] = '0'+temp%2;
                if(str[j] == '0'){
                    count --; //从１变成０
                }else{
                    count ++; //从０变成１
                }
                if(!carry){
                    break;
                }
            }
            if(carry){
                str = "1" + str;
                count ++; //最高位多了一个１
            }
            res.push_back(count);
        }
        return res;
    }
};

//int main(){
//    int num = 5;
//    vector<int> res = (new Solution)->countBits(num);
//    for(int bit : res){
//        cout<<bit<<" ";
//    }
//}
