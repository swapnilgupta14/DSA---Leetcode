class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& sand) {
        int  n = s.size();
        map<int,int>mp;
        queue<int>q;
        stack<int>st;
        reverse(sand.begin(),sand.end());
        for(int i=0;i<n;i++)
        {
            q.push(s[i]);
            mp[s[i]]++;
        }
        for(int i=0;i<n;i++) st.push(sand[i]);
        while(!q.empty())
        {
            if(mp[st.top()]==0) return q.size();
            if(st.top()==q.front())
            {
                mp[q.front()]--;
                st.pop();
                q.pop();
            }
            else {
                int x = q.front();
                q.pop();
                q.push(x);

            }


        }
        return 0;

    }
};