//
// Created by vera on 19-3-28.
//
#include <iostream>
#include <set>
using namespace std;
int main(){
    //multiset允许拥有多个等价的值
    multiset<int> multiset1 = {1, 1, 2, 2};
    set<int> set1 = {1, 1, 2, 2};
    cout<<"multiset: "<<multiset1.count(1)<<" set: "<<set1.count(1)<<endl;
}