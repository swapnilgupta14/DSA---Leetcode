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
    void preOrder(TreeNode* root, int val, int depth, int currLevel){
        if(!root)   return;
        if(currLevel == depth-1){
            TreeNode* left = root->left ;
            TreeNode *right = root->right; 

            TreeNode *newLeft = new TreeNode(val);
            TreeNode *newRight = new TreeNode(val);

            newLeft->left = left;
            newRight->right = right;

            root->left = newLeft;
            root->right = newRight;

            return ;
        }
        preOrder(root->left, val, depth, currLevel+1);
        preOrder(root->right, val, depth, currLevel+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)   return root;
        if(depth==1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        TreeNode* curr = root;
        preOrder(curr, val, depth, 1);
        return root;
    }
};