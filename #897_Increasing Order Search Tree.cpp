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
    TreeNode* increasingBST(TreeNode* root) {
        return iBST(root, NULL);
    }
private:
    TreeNode* iBST(TreeNode* root, TreeNode* nextNode){
        if(!root) return nextNode;
        TreeNode* result = iBST(root->left, root);
        root->left=NULL;
        root->right=iBST(root->right, nextNode);
        return result;
    }
};