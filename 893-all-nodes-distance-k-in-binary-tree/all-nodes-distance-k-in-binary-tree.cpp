/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void populate(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (node == NULL)
            return;
        if (node->left)
            mp.insert({node->left, node});
        if (node->right)
            mp.insert({node->right, node});
        populate(node->left, mp);
        populate(node->right, mp);
    }

    void radial(TreeNode* node, vector<int> &ans, unordered_map<TreeNode*,TreeNode*> &mp, int k){
        if(node == NULL || k < 0) return;

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited; 
        q.push(node);
        visited[node] = true;

        int steps = 0;

        while(!q.empty() && steps <= k){

            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(steps == k){
                    ans.push_back(curr->val);
                }

                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                TreeNode* parent = mp[curr];
                if(parent && !visited[parent]){
                    q.push(parent);
                    visited[parent] = true;
                }
            }
            steps++;
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        populate(root, mp);
        vector<int> ans;
        radial(target, ans, mp, k);
        return ans;
    }
};