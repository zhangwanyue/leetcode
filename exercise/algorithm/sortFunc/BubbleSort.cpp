//
// Created by vera on 19-4-10.
//
#include <iostream>
#include <vector>
using namespace std;


//将序列当中的相邻的两个元素依次比较，保证右边的元素始终大于左边的元素
//（如果是从前向后比较的顺序，那么当第一轮结束后，序列最后一个元素一定是当前序列的最大值）

//时间复杂度：最好O(n)，最差O(n^2)，平均O(n^2)
//空间复杂度：O(1)
//稳定性：稳定


void sort1(vector<int>& numbers){
    for(int i=0; i<numbers.size()-1; i++){
        bool flag = true;
        for(int j=0; j<numbers.size()-1-i; j++){ //每次将最大的元素放到最后（从前向后）
            if(numbers[j] > numbers[j+1]){
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
                flag = false;
            }
        }
        if(flag){
            break;
        }
    }
}

void sort2(vector<int> numbers){
    for(int i=0; i<numbers.size()-1; i++){
        bool flag = true;
        for(int j=numbers.size()-1; j>i; j--){ //每次将最小的元素放到最前（从后向前）
            if(numbers[j] < numbers[j-1]){
                int temp = numbers[j];
                numbers[j] = numbers[j-1];
                numbers[j-1] = temp;
                flag = false;
            }
        }
        if(flag){
            break;
        }
    }
}

int main(){
    vector<int> numbers = {4, 3, 2, 1};
    sort1(numbers);
//        sort2(numbers);
    for(int i : numbers){
        cout<<i<<" ";
    }
}



