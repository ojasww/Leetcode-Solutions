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
    bool isValidBST(TreeNode* root) {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
    bool isBSTUtil(TreeNode* node, long long int min, long long int max){
        if(node == NULL)
            return true;
        if(node->val < min || node->val > max) return false;
        return isBSTUtil(node->left, min, (long)node->val-1) &&
            isBSTUtil(node->right, (long)node->val+1, max);
    }
};