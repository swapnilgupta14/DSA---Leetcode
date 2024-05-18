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
    int postOrder(TreeNode *node, int &cnt){
        if(node == NULL) return 0;
        int lh = postOrder(node->left, cnt);
        int rh = postOrder(node->right, cnt);
        cnt += abs(lh) + abs(rh);
        return lh + rh + node->val-1;
    }
public:
    int distributeCoins(TreeNode* root) {
        if(root == NULL) return 0;
        int cnt = 0;
        postOrder(root, cnt);
        return cnt;
    }
};