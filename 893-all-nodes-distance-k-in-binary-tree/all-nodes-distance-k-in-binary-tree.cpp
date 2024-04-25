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

    void descendants(TreeNode* node, vector<int>& ans, int k) {
        if (node == NULL)
            return;
        descendants(node->left, ans, k - 1);
        descendants(node->right, ans, k - 1);
        if (k == 0) {
            ans.push_back(node->val);
            return;
        }
    }

    void precedents(TreeNode* node, vector<int> &ans, unordered_map<TreeNode*,TreeNode*> &mp, int k){
        if(node == NULL || k < 0) return;
        
        // Use BFS to find nodes that are k steps away in radial outward direction
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        
        q.push(node);
        visited.insert(node);
        
        int steps = 0;
        
        while(!q.empty() && steps <= k){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                
                // If we reach a node that is k steps away, add it to the answer
                if(steps == k){
                    ans.push_back(curr->val);
                }
                
                // Add unvisited neighbors to the queue
                if(curr->left && visited.find(curr->left) == visited.end()){
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                
                if(curr->right && visited.find(curr->right) == visited.end()){
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                
                // Add parent to the queue
                TreeNode* parent = mp[curr];
                if(parent && visited.find(parent) == visited.end()){
                    q.push(parent);
                    visited.insert(parent);
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
        // descendants(target, ans, k);
        precedents(target, ans, mp, k);
        return ans;
    }
};