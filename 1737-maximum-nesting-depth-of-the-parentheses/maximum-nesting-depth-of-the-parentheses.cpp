class Solution {
public:
    int maxDepth(std::string s) {
        int m_count = 0; 
        stack<char> st; 
        for(auto& it: s) {
            if(it == '(') {
                st.push(it);
                int s = static_cast<int>(st.size());
                m_count = max(m_count, s); 
            } else if (it == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    return -1; 
                }
            }
        }
        return st.empty() ? m_count : -1; 
    }
};
