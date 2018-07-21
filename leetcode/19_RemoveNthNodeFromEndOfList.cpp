//
// Created by vera on 18-7-21.
//


# include<iostream>

using namespace std;

/**
 * 一个简单的链表删除节点题目
 * 删除倒数第n个节点
 * 可以先计算一下有多少个节点
 * 也可以让一个指针先走n步
 */

//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pEnd = head;
        for(int i=1; i<=n; i++){//先走n步
            pEnd = pEnd->next;
        }
        ListNode* p;
        ListNode* pre;
        if(pEnd == NULL){//如果要删除的就是头结点
            return head->next;
        }else{
            p = head->next;
            pre = head;
            pEnd = pEnd->next;
        }
        while(pEnd!=NULL){ //pEnd指向最后一个节点的下一个节点时，p正好指在从后向前数的第n个节点
            pre = pre->next;
            p = p->next;
            pEnd = pEnd->next;
        }
        pre->next = p->next;
        return head;
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

    ListNode* result = (new Solution)->removeNthFromEnd(l1, 5);
    while(result != NULL){
        cout<<result->val<<" ";
        result = result->next;
    }
}
