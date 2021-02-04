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
    int findTilt(TreeNode* root) {
        int tilt=0;
        sum(root, tilt);
        return tilt;
    }
private:
    int sum(TreeNode* node, int &totalTilt){
        if(node==NULL) return 0;
        int a = sum(node->left, totalTilt);
        int b = sum(node->right, totalTilt);
        totalTilt += abs(a-b);
        return a+b+node->val;
    }
};