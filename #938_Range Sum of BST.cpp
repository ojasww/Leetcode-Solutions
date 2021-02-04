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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum=0;
        preOrderTraversal(root, L, R, sum);
        return sum;
    }
    void preOrderTraversal(TreeNode* root, int L, int R, int &sum){
        if(root==NULL)
            return;
        if(root->val <= R && root->val >= L)
            sum+=root->val;
        preOrderTraversal(root->left, L, R, sum);
        preOrderTraversal(root->right, L, R, sum);
    }
};