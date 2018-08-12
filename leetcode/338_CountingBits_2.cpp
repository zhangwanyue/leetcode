//
// Created by vera on 18-8-12.
//

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

/**
 * num/2就相当于右移一位
 * 然后再计算num%2就是计算一下右移前的最后一位
 */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        int count = 0;
        for(int i = 0; i <= num; i++) {
            ans[i] = ans[i/2] + i%2;
        }
        return ans;
    }
};

int main(){
    int num = 5;
    vector<int> res = (new Solution)->countBits(num);
    for(int bit : res){
        cout<<bit<<" ";
    }
}