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
 *
 * 注意：INT_MIN是：-2147483648; INT_MAX是：2147483647
 * 所以,dividend = -2147483648, divisor = -1也是有效输入，但是结果值会超过INT_MAX造成溢出，要将该情况特殊处理
 * 另： -2147483648/-1 = 2147483647
 *
 * abs(-2^32) = -2^32，因为-2^32的最高位就是1，本身就可以被看作正数。所以如果想对-2^32求abs，要用long int或者long long存储。
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
        long long long_dividend = abs((long long)dividend);//abs里面要强制类型转换，不然-2147483648的abs还是-2147483648
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



//int main(){
//    int a = INT_MAX;
//    cout<<a+1<<endl;
//    cout<<(new Solution)->divide(-2147483648,1)<<endl;
//}
