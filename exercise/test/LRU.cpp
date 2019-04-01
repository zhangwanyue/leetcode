//
// Created by vera on 19-3-31.
//
#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode{
    int key;
    int value;
    ListNode* next;
    ListNode* pre;
    ListNode(int key, int value){
        this->key=key;
        this->value=value;
        this->next= nullptr;
        this->pre= nullptr;
    }
};

class LRUCache{
private:
    ListNode *head, *end;
    unordered_map<int, ListNode*> lruMap;
    int capacity;
    int size;

public:
    LRUCache(int capacity){
        this->capacity = capacity;
        this->head = new ListNode(0, 0);
        this->head->next=this->end;
        this->end = nullptr;
        this->end->pre = this->head;
        size = 0;
    }

    void insertIntoHead(ListNode* listNode){
        listNode->next = head->next;
        listNode->pre = head;
        head->next = listNode;
    }

    void removeNode(ListNode* listNode){
        ListNode* pre = listNode->pre;
        ListNode* next = listNode->next;
        pre->next = next;
        next->pre = pre;
    }

    void set(int key, int value){
        auto lruIter = lruMap.find(key);
        if(lruIter != lruMap.end()){
            ListNode* currentNode = (*lruIter).second;
            currentNode->value = value;
            removeNode(currentNode);
            insertIntoHead(currentNode);
        }else{
            ListNode* listNode = new ListNode(key, value);
            insertIntoHead(listNode);
            size++;
            if(size>capacity){
                ListNode* oldEnd = end;
                end = end->pre;
                removeNode(oldEnd);
                size--;
            }
        }
    }

    int get(int key){
        auto lruIter = lruMap.find(key);
        if(lruIter != lruMap.end()){
            return (*lruIter).second->value;
        }else{
            return -1;
        }
    }

};


int main(){
    LRUCache* lruCache = new LRUCache(2);
    lruCache->set(1, 100);
    lruCache->set(2, 101);
    lruCache->set(3, 102);
    cout<<lruCache->get(1)<<endl;
    cout<<lruCache->get(2)<<endl;
    cout<<lruCache->get(3)<<endl;
}
