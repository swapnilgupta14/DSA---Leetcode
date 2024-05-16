/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    bool dfs(TreeNode* node) {
        if (node == NULL)
            return true;
        bool lh = dfs(node->left);
        bool rh = dfs(node->right);
        if (node->val == 3) {
            if (lh == 1 && rh == 1)
                return true;
            return false;
        }
        if (node->val == 2) {
            if (lh == 0 && rh == 0)
                return false;
            return true;
        }
        if (node->val == 1)
            return true;
        return false;
    }

public:
    bool evaluateTree(TreeNode* root) {
        if (root == NULL)
            return false;
        if (root->left == NULL || root->right == NULL) {
            if (root->val == 1)
                return true;
            return false;
        }
        bool res = dfs(root);
        return res;
    }
};