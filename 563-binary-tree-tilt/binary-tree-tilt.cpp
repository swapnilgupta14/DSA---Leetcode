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
    int sum = 0;
    int findTilt(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        find(root);
        return sum;
    }
    int find(TreeNode *node){
        if(node == nullptr){
            return 0;
        }
        int lh = find(node->left);
        int rh = find(node->right);
        sum += abs(lh - rh);
        return lh + rh + node->val;
    }
};