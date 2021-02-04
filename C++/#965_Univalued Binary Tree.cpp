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
    bool isUnivalTree(TreeNode* root) {
        bool flag=true;
        preOrderTraversal(root, root->val, flag);
        return flag;
    }
private:
    void preOrderTraversal(TreeNode* root, int value, bool& flag){
        if(root==NULL)
            return;
        if(root->val!=value){
            flag=false;
            return;
        }
        preOrderTraversal(root->left, value, flag);
        preOrderTraversal(root->right, value, flag);
    }
};