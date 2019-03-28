//
// Created by vera on 19-3-28.
//
#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;
int main(){
    unordered_set<int> unordered_set1 = {2,3,4,5,6};
    set<int> set1 = {2,3,4,5,6};
    for(int item : set1){
        cout<<item<<" ";
    }
    cout<<endl;
    //unordered_set内部，元素并不以任何特别顺序排序，而是组织放入桶中，元素放入哪个桶完全依赖其值的哈希，这允许对单独元素的快速访问
    for(int item : unordered_set1){
        cout<<item<<" ";
    }
    cout<<endl;
}
