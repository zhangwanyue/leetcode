//
// Created by vera on 18-7-23.
//
# include<iostream>
#include <vector>

using namespace std;

/**
 * 一道有关链表基本操作的题目
 * 这种题目，一定要记得设置头指针来做，会方便很多
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        ListNode* pre;
        ListNode* p;
        ListNode* plast = pHead;
        ListNode* pnext = head;
        //大于一个的偶数个节点
        while(pnext!=NULL && pnext->next!=NULL){
            //根据保存的pre位置更新p位置
            pre = pnext;
            p = pnext->next;
            //更新下一个pnext
            pnext = p->next;
            //该变指针所指
            plast->next = p;
            pre->next = pnext;
            //确定下一轮pnext, plast的位置
            plast = pre;
            //改变p的指向（交换）
            p->next = pre;
        }
        return pHead->next;
    }
};

int main(){
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    ListNode* newList = (new Solution)->swapPairs(l1);
    while(newList!=NULL){
        cout<<newList->val<<"->";
        newList = newList->next;
    }
}