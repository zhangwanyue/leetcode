//
// Created by vera on 19-9-15.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Node{
    int num;
    Node* lchild;
    Node* rchild;
    int lchildPath;
    int rchildPath;
    int count;
    Node(int num){
        this->num = num;
        this->count = -1;
        this->lchild = nullptr;
        this->rchild = nullptr;
    }
};

void func(Node* tree, unordered_map<int, Node*>& hashMap, int maxNum){
    for(int i=maxNum; i>0; i--){
        Node* node = hashMap[i];
        if(node->lchild == nullptr && node->rchild == nullptr){
            node->count = 0;
        }else{
            int leftCount=-1, rightCount=-1;
            if(node->lchild != nullptr && node->lchild->count!=-1){
                leftCount = node->lchild->count + node->lchildPath;
            }
            if(node->lchild == nullptr){
                leftCount = 0;
            }
            if(node->rchild != nullptr && node->rchild->count!=-1){
                rightCount = node->rchild->count + node->rchildPath;
            }
            if(node->rchild == nullptr){
                rightCount = 0;
            }
            if(leftCount!=-1 || rightCount!=-1){
                node->count = max(max(leftCount, rightCount), 0);
            }
        }
    }
    for(int i=1; i<=maxNum; i++){
        cout<<hashMap[i]->count<<" ";
    }
}

int main(){
    int n;
    cin>>n;

    unordered_map<int, Node*> hashMap;
    Node* tree = new Node(1);
    hashMap[1]=tree;

    int maxNum=1;
    int tempU, tempV, tempPath;
    for(int i=0; i<n-1; i++){
        cin>>tempU>>tempV>>tempPath;
        Node* nodeV = new Node(tempV);
        hashMap[tempV] = nodeV;
        Node* nodeU = hashMap[tempU];
        if(nodeU->lchild == nullptr){
            nodeU->lchild = nodeV;
            nodeU->lchildPath = tempPath;
        }else{
            nodeU->rchild = nodeV;
            nodeU->rchildPath = tempPath;
        }
        maxNum = tempV;
    }

    func(tree, hashMap, maxNum);
}

