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
    void helper(TreeNode* node, unordered_map<int, int> &mp){
        if(node == NULL) return;
        if(mp.find(node->val) != mp.end()){
            mp[node->val] +=1;
        }else{
            mp[node->val] = 1;
        }
        helper(node->left, mp);
        helper(node->right, mp);

    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        vector<int> ans;
        helper(root, mp);
        int ma = INT_MIN;
        for(auto it: mp){
            if(it.second > ma) ma = it.second;

        }
        for(auto it: mp){
            if(it.second == ma){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};