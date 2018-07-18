//
// Created by vera on 18-3-2.
//
# include<iostream>

using namespace std;

/**
 Definition for singly-linked list.
*/

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int a, b, current;
        ListNode* currentNode = nullptr;
        ListNode* headNode = new ListNode(0);
        ListNode* ptrNode = headNode;
        while(l1 || l2 || carry!=0){
            a = l1? l1->val : 0;
            b = l2? l2->val : 0;
            current = a + b + carry;
            currentNode = new ListNode(current%10);
            carry = current/10;

            ptrNode->next = currentNode;
            ptrNode = currentNode;

            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr;
        }
        return headNode->next;
    }
};

//int main() {
//    Solution mySolution;
//    //test set1
//    ListNode* l1_1 = new ListNode(2);
//    ListNode* l1_2 = new ListNode(4);
//    ListNode* l1_3 = new ListNode(3);
//    l1_1->next = l1_2;
//    l1_2->next = l1_3;
//
//    ListNode* l2_1 = new ListNode(5);
//    ListNode* l2_2 = new ListNode(6);
//    ListNode* l2_3 = new ListNode(4);
//    l2_1->next = l2_2;
//    l2_2->next = l2_3;
//
////    //test set2
////    ListNode* l1_1 = new ListNode(9);
////
////    ListNode* l2_1 = new ListNode(1);
////    ListNode* l2_2 = new ListNode(9);
////    ListNode* l2_3 = new ListNode(9);
////    ListNode* l2_4 = new ListNode(9);
////    ListNode* l2_5 = new ListNode(9);
////    l2_1->next = l2_2;
////    l2_2->next = l2_3;
////    l2_3->next = l2_4;
////    l2_4->next = l2_5;
//
//    ListNode* result = mySolution.addTwoNumbers(l1_1, l2_1);
//    ListNode* p = result;
//    while(p!= nullptr){
//        cout<<p->val<<"->";
//        p = p->next;
//    }
//}