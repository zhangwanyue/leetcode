//
// Created by vera on 18-7-26.
//
# include<iostream>
# include<vector>
#include <algorithm>
using namespace std;

/**
 * 这是一道数学题
 * 如果1+2+...+n就是target了，则直接求出结果
 * 否则，要寻找一个（1+2+...+n)-target为偶数的情况，这时一定存在一个1<a<n，使得2a==(1+2+...+n)-target
 * 那么1+2+...+(a-1)-a+(a+1)+...+n==target
 */
class Solution {
public:
    int reachNumber(int target) {
        //都当作正数来做
        target = abs(target);
        int step = 0;
        for (int n = 1; target > 0; n++) {
            target -= n;
            step++;
        }
        if (target == 0)
            return step;

        while (true) {//最多循环三次，一定会找到target为偶数
            if (target % 2 == 0)
                return step;
            step++;
            target -= step;
        }
    }
};

int main(){
    int target = 2;
    cout<<(new Solution)->reachNumber(target);
}