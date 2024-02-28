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
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = lefth(root);
        int rh = righth(root);
        if(lh == rh){
            return pow(2,lh) -1;
        }
        return 1+ countNodes(root->left) + countNodes(root->right); 
    }

    int lefth(TreeNode* node){
        int count=0;
        while(node){
            count++;
            node = node->left;
        }
        return count;
    }
    int righth(TreeNode* node){
        int count=0;
        while(node){
            count++;
            node = node->right;
        }
        return count;   
    }
};