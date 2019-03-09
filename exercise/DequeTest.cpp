//
// Created by vera on 19-3-9.
//

#include<iostream>
#include<deque>
#include<vector>
#include <typeinfo>
using namespace std;

void printDeque(deque<int>& deq){
    for(int i : deq){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    //静态初始化
    deque<int> deque1 = {0, 1, 2, 3};
    deque<deque<int> > deque2 = {{0, 1, 2, 3}, {0, 1, 2}};
    //元素访问
    cout<<deque1[1]<<" "<<deque2[0][1]<<endl;
    //迭代器访问
    for(deque<int>::iterator iter = deque1.begin(); iter != deque1.end(); iter++){
        cout<< *iter <<" ";
    }
    cout<<endl;
    for(auto iter = deque1.begin(); iter != deque1.end() ; iter++){
        cout<< *iter <<" ";
    }
    cout<<endl;
    for(auto item : deque1){
        cout<< item <<" ";
    }
    //双层deque迭代器访问
    for(deque<deque<int>>::iterator iter1 = deque2.begin(); iter1 != deque2.end(); iter1++){
        for(deque<int>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++){
            cout<< *iter2 <<" ";
        }
    }
    cout<<endl;
    for(auto iter1 = deque2.begin(); iter1 != deque2.end(); iter1++){
        for(auto iter2 = (*iter1).begin(); iter2 != (*iter1).end(); iter2++){
            cout<< *iter2 <<" ";
        }
    }
    cout<<endl;
    for(auto item1 : deque2){
        for(auto item2 : item1){
            cout<< item2 <<" ";
        }
    }
    cout<<endl;
    //容量
    cout<<"size:"<<deque1.size()<<" isEmpty:"<<deque1.empty()<<" max_size:"<<deque1.max_size()<<endl;
    //插入元素
    printDeque(deque1);
    deque1.insert(deque1.begin()+2, 10);//插入单个元素
    printDeque(deque1);
    int arr[] = {101, 102, 103};
    deque1.insert(deque1.begin()+3, arr, arr+3); //插入多个元素（最后一个参数是指向要添加的最后一个元素的下一个元素的迭代器）
    printDeque(deque1);
    vector<int> vec2 = {104, 105, 106};
    deque1.insert(deque1.begin()+6, vec2.begin(), vec2.end());
    printDeque(deque1);
    //erase
    deque1.erase(deque1.begin());//移除单个元素
    printDeque(deque1);
    deque1.erase(deque1.begin(), deque1.begin()+2);//移除多个元素
    printDeque(deque1);
    //push & pop
    printDeque(deque1);
    deque1.push_back(1000);
    printDeque(deque1);
    deque1.push_front(1001);
    printDeque(deque1);
    deque1.pop_back();
    printDeque(deque1);
    deque1.pop_front();
    printDeque(deque1);
    //清除全部元素
    deque1.clear();
    //比较
    deque<int> deque3 = {0,1,2,3};
    deque<int> deque4 = {0,1,2,3};
    deque<int> deque5 = {0,1,3};
    cout<< (deque3==deque4) << " " << (deque3>deque5)<<endl;

}