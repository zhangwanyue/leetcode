//
// Created by vera on 19-4-1.
//
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

struct Node{
    int key;
    int value;
    Node(int key, int value){
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
private:


public:
    list<Node> lruList;
    unordered_map<int, list<Node>::iterator> lruMap;
    int capacity;
    int size;


    LRUCache(int capacity){
        this->capacity = capacity;
        size = 0;
    }

    int get(int key){
        auto lruMapIter = lruMap.find(key);
        if(lruMapIter != lruMap.end()){
            list<Node>::iterator lruListIter = lruMapIter->second;
            lruList.erase(lruListIter);
            lruList.push_front(*lruListIter);
            return lruListIter->value;
        }else{
            return -1;
        }
    }

    void set(int key, int value){
        auto lruMapIter = lruMap.find(key);
        if(lruMapIter != lruMap.end()) {
            list<Node>::iterator lruListIter = lruMapIter->second;
            lruList.erase(lruListIter);
            lruMap.erase(lruListIter->key);
            size--;
        }
        Node node = Node(key, value);
        lruList.push_front(node);
        lruMap.insert({key, lruList.begin()});
        size++;
        if(size>capacity){
            lruMap.erase(lruList.end()->key);
            lruList.erase(lruList.end());
            size--;
        }
    }
};

void printList(list<Node> nodeList){
    for(list<Node>::iterator iter = nodeList.begin(); iter!=nodeList.end();iter++){
        cout<<iter->key<<" "<<iter->value<<endl;
    }
}

int main(){
    LRUCache* lruCache = new LRUCache(3);
    lruCache->set(1, 100);
    lruCache->set(2, 101);
    lruCache->set(3, 102);

//    cout<<lruCache->get(1)<<endl;
    lruCache->set(4, 103);

    printList(lruCache->lruList);

//    cout<<lruCache->get(1)<<endl;
//    cout<<lruCache->get(2)<<endl;
//    cout<<lruCache->get(3)<<endl;
//    cout<<lruCache->get(4)<<endl;
}