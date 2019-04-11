//
// Created by vera on 19-4-8.
//
#include <iostream>
#include <vector>

using namespace std;


//归并排序是采用分治法
//归并排序要做的就是分解和合并这两件事
//分解：将序列每次折半拆分（递归到最底层，分解为单个元素，然后将两组单个的元素merge，再将merge好的两组两个的元素merge...）
//合并：将划分后的序列段两两排序合并
//要用到额外的空间，空间复杂度为n

void merge(vector<int>& numbers, int left, int mid, int right, vector<int>& temp){
    int i = left;
    int j = mid+1;
    int t = 0;
    while(i<=mid && j<=right){
        if(numbers[i]<=numbers[j]){
            temp[t] = numbers[i];
            t++;i++;
        }else{
            temp[t] = numbers[j];
            t++;j++;
        }
    }
    while(i<=mid){
        temp[t]=numbers[i];
        t++;i++;
    }
    while(j<=right){
        temp[t]=numbers[j];
        t++;j++;
    }
    for(t=0;left<=right;t++,left++){//将temp中的元素全部copy到原数组中
        numbers[left]=temp[t];
    }
}
void sort(vector<int>& numbers, int left, int right, vector<int>& temp){
    if(left<right){
        int mid = (left+right)/2;
        sort(numbers, left, mid, temp); //左边归并
        sort(numbers, mid+1, right, temp); //右边归并
        merge(numbers, left, mid, right, temp); //其实排序的关键都在合并
    }
}

void sort(vector<int>& numbers){
    vector<int> temp;
    temp.reserve(numbers.size());//在排序前先建好一个长度等于原数组长度的临时数组，避免递归中频繁开辟空间
    sort(numbers, 0, numbers.size()-1, temp);
}

int main(){
    vector<int> numbers = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    sort(numbers);
    for(int i : numbers){
        cout<<i<<" ";
    }
}