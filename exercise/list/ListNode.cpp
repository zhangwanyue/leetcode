//
// Created by vera on 19-3-30.
//
#include <iostream>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
};

void AddToTail(ListNode** pHead, int value){
    ListNode* pNew = new ListNode();
    pNew->value = value;
    pNew->next = nullptr;
    if(*pHead == nullptr){
        *pHead = pNew; //因为想要改变pHead的值，所以要用*pHead去改
    }else{
        ListNode* pNode = *pHead;
        while (pNode->next != nullptr){
            pNode = pNode->next;
        }
        pNode->next = pNew;
    }
}


int main(){
    ListNode* pHead = nullptr;
    AddToTail(&pHead, 10);
    ListNode* pNode = pHead;
    while(pNode != nullptr){
        cout<<pNode->value<<" ";
        pNode = pNode->next;
    }
}
