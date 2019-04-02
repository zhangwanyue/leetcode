//
// Created by vera on 19-4-2.
//
#include<iostream>
#include<list>
using namespace std;
int main() {
    list<int> list1 = {0, 1, 2, 3, 4, 5, 6};
    list<int>::iterator listIter = list1.begin();
    list1.erase(listIter);
    list1.push_front(*listIter);
    cout<<(*listIter)<<endl;
}