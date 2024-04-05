class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(int i = 0 ; i < s.length();i++){

            if(st.empty() ){
                st.push(s[i]);
            }else{
                char top = st.top();
                if(abs(top-s[i]) == 32){
                    st.pop();
                }else{
                    st.push(s[i]);
                }

            }
        }

        string p ;
        while(!st.empty()){
               char c = st.top();
            st.pop();
            p.push_back(c);
        }
        reverse(p.begin(),p.end());

        return p;
        
    }
};