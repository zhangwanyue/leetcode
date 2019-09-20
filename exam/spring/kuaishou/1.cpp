//
// Created by vera on 19-3-30.
//
#include<iostream>
#include <vector>
#include <queue>

using namespace std;

//答案不对，不知道为啥……

bool checkLeftChild(vector<double >& bst, int root, int n, int size){
    queue<int> q;
    q.push(n);
    if(bst[n]>=root)
        return false;
    while(true){
        int temp = q.front();
        q.pop();
        if(2*temp+2<size){
            q.push(2*temp+1);//推入左子树
            q.push(2*temp+2);//推入右子树
            if(bst[2*temp+1]>=root || bst[2*temp+2]>=root){
                cout<<root<<endl;
                return false;
            }
        }else{
            break;
        }
    }
    return true;
}

bool checkRightChild(vector<double>& bst, int root, int n, int size){
    queue<int> q;
    q.push(n);
    if(bst[n]<=root)
        return false;
    while(true){
        int temp = q.front();
        q.pop();
        if(2*temp+2<size){
            q.push(2*temp+1);//推入左子树
            q.push(2*temp+2);//推入右子树
            if(bst[2*temp+1]<=root || bst[2*temp+2]<=root){
                cout<<root<<endl;
                return false;
            }
        }else{
            break;
        }
    }
    return true;
}

int main(){
    vector<double> bst;
    int node, size=0;
//    while(cin>>node){
//        bst.push_back(node);
//        size++;
//    }
        bst = {10, 7, 20, 2, 9, 13, 25, 1, 3, 8, 9.5, 11, 15, 21, 27};
        size = 15;
    int tempSize = size+1;
    //检查长度是否符合
    while(tempSize>1){
        if(tempSize%2 == 0){
            tempSize=tempSize/2;
        } else {
            cout<<"False";
            return 0;
        }
    }
    for(int i=0;i<size;i++){
        if(2*i+2<size){
            int root = bst[i];
            int leftChild = 2*i+1;
            int rightChild = 2*i+2;
            if(!checkLeftChild(bst, root, leftChild, size) || !checkRightChild(bst, root, rightChild, size)){
                cout<<"False";
                return 0;
            }
        }
    }
    cout<<"True";
    return 0;
}


