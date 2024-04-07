class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left_stack, star_stack;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left_stack.push(i);
            } else if (s[i] == '*') {
                star_stack.push(i);
            } else {
                if (!left_stack.empty()) {
                    left_stack.pop();
                } else if (!star_stack.empty()) {
                    star_stack.pop();
                } else {
                    return false;
                }
            }
        }
        
        while (!left_stack.empty() && !star_stack.empty()) {
            if (left_stack.top() > star_stack.top()) {
                return false;
            }
            left_stack.pop();
            star_stack.pop();
        }
        
        return left_stack.empty();
    }
};
