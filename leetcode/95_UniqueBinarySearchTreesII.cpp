//
// Created by vera on 18-8-19.
//
# include <iostream>
# include <vector>

using namespace std;
/**
 * BST树相关
 * 用递归去做的题目
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> tree;
        if (n == 0) return tree;
        return generate(1, n);
    }
private:
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> subTree;
        if(start > end){
            subTree.push_back(NULL);
            return subTree;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*> leftSubs = generate(start, i-1);
            vector<TreeNode*> rightSubs = generate(i+1, end);
            for(int j=0; j<leftSubs.size(); j++){
                for(int k=0; k<rightSubs.size(); k++){
                    TreeNode* node = new TreeNode(i);
                    node->left = leftSubs[j];
                    node->right = rightSubs[k];
                    subTree.push_back(node);
                }
            }
        }
        return subTree;
    }
};

int main() {
    vector<TreeNode *> res = (new Solution)->generateTrees(0);
    return 0;
}