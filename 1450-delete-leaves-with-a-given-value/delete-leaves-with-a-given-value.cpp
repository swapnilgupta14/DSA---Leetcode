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
    TreeNode* dfs(TreeNode* node, int target){
        if(node == NULL) return node;
        if(node->val == target && !node->left && !node->right) return node;
        TreeNode* lh = dfs(node->left, target);
        TreeNode* rh = dfs(node->right, target);
        if(lh && lh->val == target&& lh->left == NULL && lh->right == NULL) node->left = NULL;
        if(rh && rh->val == target && rh->left == NULL && rh->right == NULL) node->right = NULL;
        return node;
        

    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL) return root;
        TreeNode* temp = dfs(root, target);
        if(temp->val == target && temp->left == NULL && temp->right ==NULL) temp = NULL;
        return temp;
    }
};