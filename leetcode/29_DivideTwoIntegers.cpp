//
// Created by vera on 18-7-25.
//
# include<iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

/**
 * 题目中不让使用乘除法
 * 但是我们可以使用移位，左移位一位，相当于乘以2
 * 假设: divisor*n = dividend
 * 一定有: n = 2^a0 + 2^a1 + ... + 2^am;
 * 现在要求得: a0, a1, ..., am的值
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        if (divisor == 0)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) {
            //INT_MIN是：-2147483648; INT_MAX是：2147483647
            //这里为了防止溢出
            return INT_MAX;
        }
        long long long_dividend = abs((long long)dividend);//abs里面要强制类型转换，不然-2147483648会被abs当作正数
        long long long_divisor = abs((long long)divisor);
        while (long_dividend >= long_divisor) {  // Main loop
            int shift = 0;
            while ((long_divisor << shift) <= long_dividend){
                shift++;
            }
            result += 1 << (shift - 1);
            long_dividend -= long_divisor << (shift - 1);
        }
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))   // Positive and negative
            return result;
        else
            return -result;
    }
};



int main(){
    cout<<(new Solution)->divide(-2147483648,1)<<endl;
}
