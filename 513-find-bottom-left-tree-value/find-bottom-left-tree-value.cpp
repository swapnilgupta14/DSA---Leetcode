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
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        int leftmostValue = root->val;
        find(root, 0, maxDepth, leftmostValue);
        return leftmostValue;
    }

    int find(TreeNode *node, int depth, int &maxDepth, int &leftmostValue){
        if(node == nullptr){
            return 0;
        }
        if(depth > maxDepth){
            maxDepth = depth;
            leftmostValue = node->val;
        }
        int lh = find(node->left, depth + 1, maxDepth, leftmostValue);
        int rh = find(node->right, depth + 1, maxDepth, leftmostValue);
        return max(lh, rh) + 1;
    }
};