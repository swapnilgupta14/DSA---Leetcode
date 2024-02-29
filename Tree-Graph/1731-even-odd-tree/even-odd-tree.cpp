class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        int level = 0;
        bool isEvenLevel = true; 
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int prevVal = isEvenLevel ? INT_MIN : INT_MAX;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (isEvenLevel && (node->val % 2 == 0 || node->val <= prevVal)) {
                    return false;
                } else if (!isEvenLevel && (node->val % 2 == 1 || node->val >= prevVal)) {
                    return false;
                }
                prevVal = node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            isEvenLevel = !isEvenLevel;
        }
        return true;
    }
};
