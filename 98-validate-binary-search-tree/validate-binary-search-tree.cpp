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
    bool check(TreeNode* root,long int mini,long int maxi){
        if(root==NULL) return true;
        if(root->val<=mini || root->val>=maxi){
            return false;
        }
        bool left=check(root->left,mini,root->val);
        if(left==false) return false;
        bool right=check(root->right,root->val,maxi);
        if(right==false) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        
        long int maxi=LONG_MAX;
        long int mini=LONG_MIN;
        if(check(root,mini,maxi)){
            return true;
        }
        return false;
        
        
    }
};
// class Solution {
// private: 
//     bool check(TreeNode* node){
//         if(node == NULL) return true;
//         bool lh = check(node -> left);
//         bool rh = check(node-> right);
//         if(lh && rh){
//             if(node->left) if(node->val <= node->left->val) return false;
//             if(node->right) if(node->val >= node->right->val) return false;
//             return true;
//         } 
//         return false;
//     }
// public:
//     bool isValidBST(TreeNode* root) {
//         if(root == NULL) return true;
//         int value = root->val;
//         if(check(root) ) return true;
//         return false;
//     }
// };