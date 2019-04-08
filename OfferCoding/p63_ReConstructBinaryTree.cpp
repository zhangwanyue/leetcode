//
// Created by vera on 19-4-2.
//
#include <iostream>
#include <queue>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return reConstructBinaryTreeCore(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
    }

    TreeNode* reConstructBinaryTreeCore(vector<int> pre, vector<int> vin, int preBegin, int preEnd, int vinBegin, int vinEnd){
        TreeNode* treeNode = new TreeNode(pre[preBegin]);
        if(preBegin == preEnd){
            return treeNode;
        }else{
            int leftPreBegin, leftPreEnd, leftVinBegin, leftVinEnd, rightPreBegin, rightPreEnd, rightVinBegin, rightVinEnd;
            int findInVin;
            for(findInVin=vinBegin; findInVin<=vinEnd; findInVin++){
                if(vin[findInVin] == pre[preBegin]){
                    break;
                }
            }
            if(findInVin == vinBegin){//没有左子树
                rightPreBegin = preBegin+1;
                rightPreEnd = preEnd;
                rightVinBegin = vinBegin+1;
                rightVinEnd = vinEnd;
                treeNode->left = nullptr;
                treeNode->right = reConstructBinaryTreeCore(pre, vin, rightPreBegin, rightPreEnd, rightVinBegin, rightVinEnd);
            }else if(findInVin == vinEnd){//没有右子树
                leftPreBegin = preBegin+1;
                leftPreEnd = preEnd;
                leftVinBegin = vinBegin;
                leftVinEnd = vinEnd-1;
                treeNode->left = reConstructBinaryTreeCore(pre, vin, leftPreBegin, leftPreEnd, leftVinBegin, leftVinEnd);
                treeNode->right = nullptr;
            }else{//左右子树都有
                int leftLen = findInVin-vinBegin;

                leftPreBegin = preBegin+1;
                leftPreEnd = preBegin+leftLen;
                rightPreBegin = leftPreEnd+1;
                rightPreEnd = preEnd;

                leftVinBegin = vinBegin;
                leftVinEnd = findInVin-1;
                rightVinBegin = findInVin+1;
                rightVinEnd = vinEnd;

                treeNode->left = reConstructBinaryTreeCore(pre, vin, leftPreBegin, leftPreEnd, leftVinBegin, leftVinEnd);
                treeNode->right = reConstructBinaryTreeCore(pre, vin, rightPreBegin, rightPreEnd, rightVinBegin, rightVinEnd);
            }
            return treeNode;
        }
    }
};

list<list<int> > printTreeNodeFloors(TreeNode* root){
    queue<TreeNode> treeNodeQueue;
    list<list<int> > treeNodeList;//按层存储树
    treeNodeQueue.push(*root);
    while(!treeNodeQueue.empty()){
        int len = treeNodeQueue.size(); //用len记录当前层的长度
        list<int> nodeFloorList;
        while((len--)> 0){
            TreeNode currentTreeNode = treeNodeQueue.front();
            nodeFloorList.push_back(currentTreeNode.val);
            treeNodeQueue.pop();
            if(currentTreeNode.left!= nullptr){
                treeNodeQueue.push(*(currentTreeNode.left));
            }
            if(currentTreeNode.right!= nullptr){
                treeNodeQueue.push(*(currentTreeNode.right));
            }
        }
        treeNodeList.push_back(nodeFloorList);
    }
    for(list<int> list1 : treeNodeList){
        for(int item : list1){
            cout<<item<<" ";
        }
        cout<<endl;
    }
    return treeNodeList;
}

int main(){
//    TreeNode* root = new TreeNode(0);
//    TreeNode* node1 = new TreeNode(1);
//    TreeNode* node2 = new TreeNode(2);
//    TreeNode* node3 = new TreeNode(3);
//    TreeNode* node4 = new TreeNode(4);
//    TreeNode* node5 = new TreeNode(5);
//    TreeNode* node6 = new TreeNode(6);
//
//    root->left = node1;
//    root->right = node2;
//    node1->left = node3;
//    node1->right = node4;
//    node2->left = node5;
//    node2->right = node6;
//
//    printTreeNodeFloors(root);
//
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    TreeNode* root = (new Solution)->reConstructBinaryTree(pre, vin);
    printTreeNodeFloors(root);
}