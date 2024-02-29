class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) {
            return true; // Empty tree is considered an even-odd tree
        }

        int level = 0;
        bool isEvenLevel = true; // Track expected parity for current level
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int prevVal = isEvenLevel ? INT_MIN : INT_MAX; // Compare values based on parity

            // Process nodes at the current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Check if the node's value violates the even-odd property
                if (isEvenLevel && (node->val % 2 == 0 || node->val <= prevVal)) {
                    return false;
                } else if (!isEvenLevel && (node->val % 2 == 1 || node->val >= prevVal)) {
                    return false;
                }

                // Update comparison value and add children to queue
                prevVal = node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            // Switch parity for the next level
            isEvenLevel = !isEvenLevel;
        }

        return true; // All levels processed without violations
    }
};
