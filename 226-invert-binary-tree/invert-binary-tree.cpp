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
private:
    void helper(TreeNode* node){
        if(node == NULL) return;
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        helper(node->left);
        helper(node->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL || (root->left == NULL) && (root->right == NULL)) return root;
        TreeNode* temp = root;
        helper(root);
        return temp;
    }
};