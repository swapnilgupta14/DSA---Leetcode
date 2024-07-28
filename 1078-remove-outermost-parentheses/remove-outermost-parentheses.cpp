class Solution {
public:
    string removeOuterParentheses(string s) {
        if(s.size() == 0) return s;

        stack<char> st;
        string ans;
        int point = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push('(');
            }else{
                st.pop();
            }
            if(st.empty()){
                ans += s.substr(point+1, i-point-1);
                point = i+1;
            }
        }
        return ans;

    }
};