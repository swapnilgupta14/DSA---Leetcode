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
    bool isEvenOddTree(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        bool evenLevel = true;

        while(!q.empty()){
            int s = q.size();
            int previous = (evenLevel) ? INT_MIN : INT_MAX;
            for(int i =0 ; i<s ; i++){
                TreeNode* node = q.front();
                q.pop();

                if(evenLevel && ((node->val % 2) == 0 || node->val <= previous) ){
                    return false;
                }else if(!evenLevel && ((node->val %2) == 1 || node->val >= previous)){
                    return false;
                }
                previous = node->val;
                if(node->left){
                    q.push(node->left);}
                if(node->right){
                    q.push(node->right);
                }
            }
            evenLevel = !evenLevel;

        }
        return true;
    }
};