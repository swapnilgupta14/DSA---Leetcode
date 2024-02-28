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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        TreeNode * ans = root;
        solve(root);
        return ans;
        
    }
    void solve(TreeNode *node){
        if(node){
            TreeNode *temp = node->left;
            node->left = node->right;
            node->right = temp;
            solve(node->left);
            solve(node->right);
        }
        return;
    }
};