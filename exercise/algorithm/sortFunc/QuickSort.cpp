//
// Created by vera on 19-4-10.
//
#include <iostream>
#include <vector>
using namespace std;

//快排的基本思想：挖坑填数＋分治法｀
//1.从序列中选择一个基准数（最简单的可以选择第一个数为基准数，三数取中法则选择start,mid,end三数中间大小的一个数为基准数）
//2.将序列当中所有数依次遍历，比基准数大的放在其右侧，比基准数小的放在其左侧（挖坑填数）
//3.重复步骤1.2.直到所有子集当中只有一个元素为止（分治）


//时间复杂度：最好/平均：O(nlogn)，最差：O(n^2)
//空间复杂度：最好/平均：O(logn)，最差：O(n)（使用原地排序。最好/平均需要O(logn)次递归调用，每次递归调用需要一个空间，所以需要O(logn)的空间；最差需要O(n)次递归调用，每次递归调用需要一个空间，所以需要O(n)的空间）
//稳定性：不稳定（pivot和numbers[i]交换的时候，就可能把元素的稳定性打乱）

//挖坑填数
int partition(vector<int>& numbers, int start, int end){
    int pivot = numbers[start];//现在numbers[start]是个坑，要找个数填一下
    while(start<end){
        while(start<end && numbers[end]>=pivot) {
            --end;
        }
        numbers[start] = numbers[end    ]; //现在把numbers[start]这个坑填了，但是numbers[end]变成了坑，要找个数填一下
        while(start<end && numbers[start]<=pivot){
            ++start;
        }
        numbers[end] = numbers[start]; //现在把numbers[end]这个坑填了，但是numbers[start]变成了坑，要找个数填一下
    }
    numbers[start] = pivot;//最后把numbers[start]这个坑填了
    return start;
}

//分治
void quicksort(vector<int>& numbers, int start, int end){
    if(start<end){
        int pivot = partition(numbers, start, end);
        quicksort(numbers, start, pivot-1);
        quicksort(numbers, pivot+1, end);
    }
}


int main(){
    vector<int> numbers = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    quicksort(numbers, 0, numbers.size()-1);
    for(int i : numbers){
        cout<<i<<" ";
    }
}


