//
// Created by vera on 19-3-30.
//
#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
};

//向链表末尾插入一个节点
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

//删除链表中的节点
void RemoveNode(ListNode** pHead, int value){
    if(pHead == nullptr || *pHead == nullptr){
        return;
    }
    ListNode* pToDeleted = nullptr;
    if((*pHead)->value == value){//如果要刪除的是头结点
        pToDeleted = *pHead;
        *pHead = (*pHead)->next;
    }else{
        ListNode* pNode = *pHead;
        while(pNode->next!=nullptr && pNode->next->value!=value){
            pNode = pNode->next;
        }
        if(pNode->next != nullptr && pNode->next->value==value){
            pToDeleted = pNode->next;
            pNode->next = pNode->next->next;
        }
    }
    if(pToDeleted != nullptr){
        delete  pToDeleted;
        pToDeleted = nullptr;
    }
}

void printList(ListNode* pHead){
    ListNode* pCurrent = pHead;
    while(pCurrent!= nullptr){
        cout<<pCurrent->value<<" ";
        pCurrent = pCurrent->next;
    }
    cout<<endl;
}

//倒序输出链表:使用栈
void PrintListReversingly_stack(ListNode* pHead){
    stack<ListNode> nodeStack;
    ListNode* pCurrent = pHead;
    while(pCurrent != nullptr){
        nodeStack.push(*pCurrent);
        pCurrent = pCurrent->next;
    }
    while(!nodeStack.empty()){
        ListNode node = nodeStack.top();
        nodeStack.pop();
        cout<<node.value<<" ";
    }
    cout<<endl;
}

//倒序输出链表:使用递归
void PrintListReversingly_Recursively(ListNode* pHead){
    if(pHead!=nullptr){
        PrintListReversingly_Recursively(pHead->next);
        cout<<pHead->value<<" ";
    }
}

int main(){
    ListNode* pHead = nullptr;
    AddToTail(&pHead, 10);
    AddToTail(&pHead, 20);

    PrintListReversingly_Recursively(pHead);
    cout<<endl;
    printList(pHead);

    RemoveNode(&pHead, 10);
    printList(pHead);

}
