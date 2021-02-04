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
    int maxDepth(TreeNode* root) {
        //DFS
        if(root==NULL) return 0;
        int depth=0, maxdepth=0;
        calcDepth(root, depth, maxdepth);
        return maxdepth+1;
    }
    void calcDepth(TreeNode* root, int &depth, int &maxdepth){
        if(root->left!=NULL)
            calcDepth(root->left, ++depth, maxdepth);
        if(root->right!=NULL)
            calcDepth(root->right, ++depth, maxdepth);
        maxdepth=max(maxdepth, depth);
        depth--;
    }
};