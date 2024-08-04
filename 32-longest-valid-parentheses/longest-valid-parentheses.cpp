class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int maxLen = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            } else {
                st.pop();
                if(!st.empty()){
                    int len = i - st.top();
                    maxLen = max(len, maxLen);

                } else
                     st.push(i);
            }
        }
        return  maxLen;
        
    }
};