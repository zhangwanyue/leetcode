//
// Created by vera on 18-8-19.
//
# include <iostream>
# include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return *generate(1, 0);
        return *generate(1, n);
    }
private:
    vector<TreeNode *>* generate(int start, int end){
        vector<TreeNode *> *subTree = new vector<TreeNode*>;
        if(start > end){
            return subTree;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*>* leftSubs = generate(start, i-1);
            vector<TreeNode*>* rightSubs = generate(i+1, end);
            for(int j=0; j<rightSubs->size(); j++){
                
            }
        }

    }


};

int main() {

}