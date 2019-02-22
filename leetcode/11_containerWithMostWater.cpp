//
// Created by vera on 18-7-19.
//
# include<iostream>
#include <vector>

using namespace std;
/**
 * 关键点在于，储水量取决于最短的一条线的长度和两条线的距离
 * 设定头尾指针，最开始分别指向最远的两条线
 * 后面每次只移动短线的指针（因为只有这样才可能在移动之后，储水量大于移动前）
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxSize = 0, tempMax = 0;
        for(int head=0, tail=height.size()-1; head<tail;){
            if(height[head]>height[tail]){
                tempMax = height[tail] * (tail-head);
                tail--;
            }else{
                tempMax = height[head] * (tail-head);
                head++;
            }
            if(tempMax>maxSize){
                maxSize = tempMax;
            }
        }
        return maxSize;
    }
};

//int main(){
//    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//    cout<<(new Solution)->maxArea(height)<<endl;
//}