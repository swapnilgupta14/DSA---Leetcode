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
    vector<int> ans1;
    vector<int> ans2;
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return false;
        }
        if((root -> left != nullptr && root-> right == nullptr)&&(root -> left != nullptr && root-> right == nullptr)){
            return false;
        }
        find1(root->left);
        find2(root->right);
        for(auto i : ans1){
            cout<<i<<" ";
        }
        if(ans1 == ans2){
            return true;
        }
        return false;
    }
    void find1(TreeNode* node){
        // performing preorder 
        if(node == nullptr){
            ans2.push_back(9999);
            return;
        }
        ans2.push_back(node->val);
        find1(node->left);
        find1(node->right);
    }

    void find2(TreeNode* node){
        // performing revese preorder
        if(node == nullptr){
            ans1.push_back(9999);
            return;
        }
        ans1.push_back(node->val);
        find2(node->right);
        find2(node->left);
    }
};