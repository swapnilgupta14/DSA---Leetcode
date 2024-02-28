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
    vector <int> first;
    vector <int> second;
    void traversal(TreeNode *root, int which){
        if(root == nullptr){
            if(which == 1){
            first.push_back(9999);
        }
        if(which == 2){
            second.push_back(9999);
        }
            return;
        }
        traversal(root->left, which);
        traversal(root->right, which);
        if(which == 1){
            first.push_back(root->val);
        }
        if(which == 2){
            second.push_back(root->val);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        traversal(p,1);
        traversal(q,2);
        for(int i:first){
            cout<< i << " ";
        }
        for(int i:second){
            cout<< i << " ";
        }
        if(first == second){
            return true;
        }
        return false;
    }
};