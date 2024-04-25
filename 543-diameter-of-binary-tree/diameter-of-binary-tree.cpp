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
    int helper(TreeNode* node, int &max_dia){
        if(node == NULL) return 0;
        int lh = helper(node->left, max_dia);
        int rh = helper(node->right, max_dia);
        max_dia = max(max_dia, lh+rh);
        return (1 + max(lh, rh));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int max_dia = 0;
        helper(root, max_dia);
        return max_dia; 
    }
};

