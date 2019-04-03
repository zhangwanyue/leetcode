//
// Created by vera on 19-4-2.
//
#include<iostream>
#include<list>
#include <vector>

using namespace std;

void printList(list<int> list1){
    for(int item : list1){
        cout<<item<<" ";
    }
    cout<<endl;
}

int main() {
    list<int> list1 = {0, 1, 2, 3, 4, 5, 6};
    list<int>::iterator listIter = list1.begin();
    list1.erase(listIter);
    list1.push_front(*listIter);
    cout<<(*listIter)<<endl;

    for(list<int>::iterator listIter2 = list1.begin(); listIter2!=list1.end();){
        if((*listIter2)%2 == 0){
            listIter2 = list1.erase(listIter2); //返回被移除的元素的下一个元素,如果移除的是最后一个元素,则返回end()
        }else{
            listIter2++;
        }
    }

    printList(list1);


}