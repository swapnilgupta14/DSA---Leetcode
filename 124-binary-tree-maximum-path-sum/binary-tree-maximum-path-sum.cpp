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
    int maxPathSum(TreeNode* root) {
        int maxi = root->val;
        find(root , maxi);
        return maxi;
    }
private:
    int find(TreeNode* node, int &maxi){
        if(node == nullptr){
            return 0;
        }
        int lh = max(find(node->left, maxi), 0);
        int rh = max(find(node->right, maxi), 0);
        maxi = max(maxi , node->val+lh+rh);
        return node->val+max(lh,rh);
    }
};