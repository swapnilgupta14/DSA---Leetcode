class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {  
        unordered_set<string> st;
        for(string s : wordList){
            st.insert(s);
        }
        if(st.find(endWord) == st.end()){
            return 0;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto [w,d] = q.front() ; q.pop();
            for(int i = 0 ; i < w.size() ; i++){
                char t = w[i];
                for(char c = 'a' ; c <= 'z' ; c++){
                    w[i] = c ;
                    if(st.count(w)){
                        if(w == endWord) return d+1;
                        st.erase(w);
                        q.push({w,d+1});
                    }
                }
                w[i] = t ;
            }
        }
        return 0;
    }
};
