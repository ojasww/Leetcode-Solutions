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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        int low = 0, high=nums.size()-1;
        return sortedArrayToBSTUtil(nums, low, high);
    }
    TreeNode* sortedArrayToBSTUtil(vector<int>& nums, int low, int high){
        if(low>high) return NULL;
        int mid = low + (high-low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTUtil(nums, low, mid-1);
        root->right = sortedArrayToBSTUtil(nums, mid+1, high);
        return root;
    }
};