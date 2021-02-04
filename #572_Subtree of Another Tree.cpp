/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL) return false;
        if(t==NULL) return true;
        if(areIdenticalTrees(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    bool areIdenticalTrees(TreeNode* s, TreeNode* t){
        if(s==NULL && t==NULL) return true;
        if(s==NULL || t==NULL) return false;
        return ((s->val == t->val) && areIdenticalTrees(s->left, t->left) &&
            areIdenticalTrees(s->right, t->right));
    }
};