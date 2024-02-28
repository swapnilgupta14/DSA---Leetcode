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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int s = q.size();
            for (int i=0 ; i<s ; i++){
                TreeNode* ptr = q.front();
                q.pop();
                if(ptr->left != nullptr){
                    q.push(ptr->left);
                }
                if(ptr->right != nullptr){
                    q.push(ptr->right);
                }
                level.push_back(ptr->val);
            }
            ans.push_back(level);
        }
        vector<vector<int>> rev;
        for (int i = ans.size()-1 ; i>=0 ; i--){
            rev.push_back(ans[i]);
        }   
        return rev;

    }
};