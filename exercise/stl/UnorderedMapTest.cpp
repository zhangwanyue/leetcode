//
// Created by vera on 19-9-20.
//

#include <iostream>
#include <unordered_map>
using namespace std;

// 和java中hashmap的结构相同，数组+链表（or红黑树）
int main(){
    unordered_map<string, int> unordered_map1 = {{"Alice", 3}, {"Bob", 1}, {"Lily", 2}};

    //unordered_set内部，元素并不以任何特别顺序排序，而是组织放入桶中，元素放入哪个桶完全依赖其值的哈希，这允许对单独元素的快速访问
    for(auto item : unordered_map1){
        cout<<item.first<<" "<<item.second<<endl;
    }

    //get value using key
    cout<<unordered_map1["Alice"]<<endl;

    //find
    unordered_map<string, int>::iterator iter = unordered_map1.find("Alice");//寻找带有特定键的元素
    if(iter!=unordered_map1.end()){
        cout<<"has find"<<endl;
    }else{
        cout<<"not find"<<endl;
    }
}