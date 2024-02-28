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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue <pair<TreeNode*, pair<int,int>>> q;
        map <int, map<int, multiset<int>>> mp;
        q.push({root, {0,0}});
        while (!q.empty()){
            auto qsf = q.front();
            q.pop();
            TreeNode* ptr = qsf.first; 
            int x = qsf.second.first;
            int y = qsf.second.second;
            mp[x][y].insert(ptr->val);
            if(ptr ->left != nullptr){
                q.push({ptr->left, {x-1, y+1}});
            }
            if(ptr ->right != nullptr){
                q.push({ptr->right, {x+1, y+1}});
            }
        }

        for (auto i : mp){
            vector<int>col;
            for (auto j : i.second){
                col.insert(col.end(), j.second.begin() , j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};