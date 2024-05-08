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
    bool check(TreeNode* node, long int minVal, long int maxVal){
        if(node == NULL) return true;
        if(node->val >= maxVal || node->val <= minVal) return false;
        bool lh = check(node->left, minVal, node->val);
        bool rh = check(node->right, node->val, maxVal);
        if(rh == false || lh == false) return false;
        // if(lh==false || rh==false) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        long int maxVal=LONG_MAX;
        long int minVal=LONG_MIN;
        if(check(root, minVal, maxVal)){
            return true;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool check(TreeNode* root,long int mini,long int maxi){
//         if(root==NULL) return true;
//         if(root->val<=mini || root->val>=maxi){
//             return false;
//         }
//         bool left=check(root->left,mini,root->val);
//         if(left==false) return false;
//         bool right=check(root->right,root->val,maxi);
//         if(right==false) return false;
//         return true;
//     }
//     bool isValidBST(TreeNode* root) {
//         if(root==NULL) return true;
        
//         long int maxi=LONG_MAX;
//         long int mini=LONG_MIN;
//         if(check(root,mini,maxi)){
//             return true;
//         }
//         return false;
        
        
//     }
// };