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
        this->head = new ListNode(0, 0);//头节点
        this->end = new ListNode(0, 0);//尾节点
        head->next=end;
        end->pre=head;
        size = 0;
    }

    void insertIntoHead(ListNode* listNode){
        ListNode* headNext = head->next;
        listNode->next = headNext;
        listNode->pre = head;
        head->next = listNode;
        headNext->pre=listNode;
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
            lruMap.insert({key, listNode});
            if(size>capacity){
                ListNode* oldEnd = end->pre; //更换尾节点的前一个节点
                end->pre = end->pre->pre;
                removeNode(oldEnd);
                lruMap.erase(lruMap.find(oldEnd->key));
                size--;
            }
        }
    }

    int get(int key){
        auto lruIter = lruMap.find(key);
        if(lruIter != lruMap.end()){
            ListNode* currentNode = (*lruIter).second;
            removeNode(currentNode);
            insertIntoHead(currentNode);
            return (*lruIter).second->value;
        }else{
            return -1;
        }
    }

};


int main(){
    LRUCache* lruCache = new LRUCache(3);
    lruCache->set(1, 100);
    lruCache->set(2, 101);
    lruCache->set(3, 102);
    cout<<lruCache->get(1)<<endl;
    lruCache->set(4, 103);
    cout<<lruCache->get(1)<<endl;
    cout<<lruCache->get(2)<<endl;
    cout<<lruCache->get(3)<<endl;
    cout<<lruCache->get(4)<<endl;
}
