//
// Created by vera on 19-6-20.
//
#include <iostream>
#include <vector>

using namespace std;

//假设堆的root的下标是0（即下标从0开始）
//则heap[i]的左孩子是heap[i*2+1]，右孩子是heap[i*2+2]
//则heap[i]的父节点是heap[(i-1)/2]


// 插入一个node到最小堆
void push(vector<int>& heap, int& size, int node){
    heap.push_back(node); // 插入到最后一个位置
    size++;
    int i = size-1;
    while(i>0){
        int parent = (i-1)/2; // 注意父节点是(i-1)/2
        if(node<heap[parent]){ // 小于父节点
            heap[i]=heap[parent]; // 将父节点放下来
            i=parent;
        }else{
            break;
        }
    }
    heap[i] = node;
}

// 从最小堆删除一个node
int pop(vector<int>& heap, int& size){
    int top = heap[0]; // root节点的下标为0
    int i=0;
    int current = heap[size-1];
    heap[0]=heap[size-1]; // 最后一个元素放到顶部
    size--;
    while(i*2+1<size-1){ // 判断当前元素还有孩子节点
        int lchild = i*2 + 1;
        int rchild = i*2 + 2;
        if(current>heap[lchild] || current>heap[rchild]){
            if(heap[lchild]<heap[rchild]){  // 把左孩子升到父节点
                heap[i] = heap[lchild];
                i = lchild;
            }else{              // 把右孩子上升到父节点
                heap[i] = heap[rchild];
                i = rchild;
            }
        }else{
            break;
        }
    }
    heap[i] = current;
    return top;
}

int main(){
    vector<int> heap={0, 1, 2, 3, 4, 5};
    int size = 6;
    while(size>0){
        cout<<pop(heap, size)<<endl;
    }

    cout<<"after insert"<<endl;
    heap.clear();
    for(int i=10; i>0; i--){
        push(heap, size, i);
    }
    while(size>0){
        cout<<pop(heap, size)<<endl;
    }

}
