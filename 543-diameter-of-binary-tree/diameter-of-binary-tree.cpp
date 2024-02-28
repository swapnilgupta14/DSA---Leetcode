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
    int diameterOfBinaryTree(TreeNode* root) {
        int count = 0;
        find(root, count);
        return count;
    }

    int find(TreeNode *root, int &count){
        if(root == nullptr) return 0;
        int lh = find(root->left,count);
        int rh = find(root->right, count);
        count = max(count, lh+rh);
        return 1 + max(lh, rh);
    }
};