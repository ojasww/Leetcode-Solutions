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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return depth(root).second;
    }
private:
    pair<int, TreeNode*> depth(TreeNode* root){
        pair<int, TreeNode*> p;
        if(root==NULL) {
            p.first = 0;
            p.second = NULL;
            return p;
        };
        pair<int, TreeNode*> l = depth(root->left), r = depth(root->right);
        int ld = l.first, rd = r.first;
        p.first = max(ld, rd)+1;
        p.second = (ld==rd) ? root : (ld>rd) ? l.second : r.second;
        return p;
    }
};