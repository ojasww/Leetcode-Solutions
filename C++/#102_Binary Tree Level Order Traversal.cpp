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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue< pair<int, TreeNode*> > q;
        q.push(make_pair(0, root));
        while(!q.empty()){
            pair<int, TreeNode*> p = q.front();
            if(result.size() <= p.first){
                vector<int> v{p.second->val};
                result.push_back(v);
            }
            else
                result[p.first].push_back(p.second->val);
            if(p.second->left != NULL){
                q.push(make_pair(p.first+1, p.second->left));
            }
            if(p.second->right != NULL){
                q.push(make_pair(p.first+1, p.second->right));
            }
            q.pop();
        }
        return result;
    }
};


//Without using pairs, less memory than above used 
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
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> result;
//         if(root == NULL) return result;
//         int level = 0;
//         queue< TreeNode* > q;
//         q.push(root);
//         while(!q.empty()){
//             int sz = q.size();
//             result.push_back(vector<int>());
//             for(int i=0; i<sz; i++){
//                 TreeNode* node = q.front();
//                 q.pop();
                
//                 result[level].push_back(node->val);
                
//                 if(node->left != NULL){
//                     q.push(node->left);
//                 }
//                 if(node->right != NULL){
//                     q.push(node->right);
//                 }
//             }
//             level++;
            
//         }
//         return result;
//     }
// };