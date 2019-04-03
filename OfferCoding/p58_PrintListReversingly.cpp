//
// Created by vera on 19-4-2.
//
#include <iostream>
#include <stack>
#include <vector>

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


vector<int> printListFromTailToHead(ListNode* head) {
    stack<int> nodeStack;
    vector<int> nodeVec;
    ListNode* pCurrent = head;
    while(pCurrent != nullptr){
        nodeStack.push(pCurrent->value);
        pCurrent = pCurrent->next;
    }
    while(!nodeStack.empty()){
        int value = nodeStack.top();
        nodeStack.pop();
        nodeVec.push_back(value);
    }
    return nodeVec;
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
}