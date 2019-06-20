//
// Created by vera on 19-4-7.
//
#include <iostream>
#include <vector>

using namespace std;

//题目：查找最后一个小于key的元素

//将题目抽象出来就是:
//vec[*]<key
//vec[*+1]>=key
//现在要证明代码和这个式子相同

//因为算法的终结条件一定是：
//left=right+1;
//又由代码可以推出
//vec[left-1]<key
//vec[right+1]>=key
//return right
//将left=right+1代入可得：
//vec[right]<key
//vec[right+1]>=key

//综上right=＝*
//证明完毕

int findLastSmaller(vector<int> vec, int key){
    int left = 0;
    int right = vec.size()-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(vec[mid] < key){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return right;
}

int main(){
    vector<int> vec = {4,5};
    int key = 3;
    cout<<findLastSmaller(vec, key);
}