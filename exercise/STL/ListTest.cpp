//
// Created by vera on 19-3-9.
//

#include<iostream>
#include<list>
#include <vector>

using namespace std;

void printList(list<int>& list1){
    for(int i : list1){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    //静态初始化
    list<int> list1 = {0, 1, 2, 3};
    list<list<int>> list2 = {{0, 1, 2, 3}, {4, 5}};
    //初始化固定大小
    list<int> listTemp(10);
    //元素访问
    cout<<list1.front()<<" "<<list1.back()<<endl;
    //迭代器
    for(list<list<int>>::iterator iterator1 = list2.begin(); iterator1 != list2.end(); iterator1++){
        for(list<int>::iterator iterator2 = (*iterator1).begin(); iterator2 != (*iterator1).end(); iterator2++)
            cout<<(*iterator2)<<" ";
    }
    cout<<endl;
    for(list<int> item1 : list2){
        for(int iterm2 : item1){
            cout<<iterm2<<" ";
        }
    }
    cout<<endl;
    //容量
    cout<<"size:"<<list1.size()<<" isEmpty:"<<list1.empty()<<" max_size:"<<list1.max_size()<<endl;
    //插入元素
    //注意：list没有重载+操作符，只重载了++操作符
    cout<<"------insert------"<<endl;
    printList(list1);
    list1.insert(list1.begin(), 10);//插入单个元素
    printList(list1);
    int arr[] = {101, 102, 103};
    list1.insert(list1.begin(), arr, arr+3); //插入多个元素（最后一个参数是指向要添加的最后一个元素的下一个元素的迭代器）
    printList(list1);
    vector<int> vec2 = {104, 105, 106};
    list1.insert(list1.begin(), vec2.begin(), vec2.end());
    printList(list1);
    //push & pop
    cout<<"----push & pop----"<<endl;
    list1.push_front(1000);
    printList(list1);
    list1.pop_front();
    printList(list1);
    list1.push_back(1001);
    printList(list1);
    list1.pop_back();
    printList(list1);
    //清除全部元素
    list1.clear();
    //比较
    cout<<"-----operator------"<<endl;
    list<int> list3 = {0,1,2,3};
    list<int> list4 = {0,1,2,3};
    list<int> list5 = {0,1,3};
    cout<< (list3==list4) << " " << (list3>list5)<<endl;
    //删除元素
    std::list<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // Erase all even numbers (C++11 and later)
    for (auto it = c.begin(); it != c.end(); ) {
        if (*it % 2 == 0) {
            it = c.erase(it);//删除迭代器指向的元素
        } else {
            ++it;
        }
    }
    printList(c);
    c.remove(1);//删除值为1的元素
    printList(c);
}