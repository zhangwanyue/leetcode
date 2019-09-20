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
    Node* father;
    int lchildPath;
    int rchildPath;
    int fatherPath;
    int count;
    Node(int num){
        this->num = num;
        this->count = -1;
        this->lchild = nullptr;
        this->rchild = nullptr;
        this->father = nullptr;
    }
};


void func(Node* tree, unordered_map<int, Node*>& hashMap, int maxNum){
    bool flag = true;
    while(true){
        for(auto it = hashMap.begin(); it!=hashMap.end();it++){
            if(it->second->lchild == nullptr && it->second->rchild == nullptr){
                it->second->count = 0;
            }else{
                int leftCount=-1, rightCount=-1;
                if(it->second->lchild != nullptr && it->second->lchild->count!=-1){
                    leftCount = it->second->lchild->count;
                }
                if(it->second->lchild == nullptr){
                    leftCount = 0;
                }
                if(it->second->rchild != nullptr && it->second->rchild->count!=-1){
                    rightCount = it->second->rchild->count;
                }
                if(it->second->rchild == nullptr){
                    rightCount = 0;
                }
                if(leftCount!=-1 && rightCount!=-1){
                    it->second->count = max(max(leftCount, rightCount), 0);
                }
            }
            if(it->second->count == -1){
                flag = false;
            }
        }
        if(flag){
            break;
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
        nodeV->father = nodeU;
        nodeV->fatherPath = tempPath;
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
