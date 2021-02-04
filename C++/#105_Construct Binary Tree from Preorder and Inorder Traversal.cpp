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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inIndex;
        return helper(0,0,inorder.size()-1, preorder, inorder);
    }
    TreeNode* helper(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(preStart>preorder.size()-1 || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int index=0;
        for(int i=inStart; i<=inEnd; i++)
            if(root->val == inorder[i])
                index=i;
        root->left = helper(preStart+1, inStart, index-1, preorder, inorder);
        root->right = helper(preStart+index-inStart+1, index+1, inEnd, preorder, inorder);
        return root;
    }
};