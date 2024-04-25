class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        unordered_map<char,int> dp;
        dp[s[0]] = 1;
        for(int i=1;i<n;i++){
            int prev = abs(s[i-1] - s[i]) <= k ? dp[s[i-1]] : 0;
            int mx = 0;
            for(int j=0; j<=k; j++){
                if(s[i]+j <= 'z'){
                    int count = dp.find(s[i]+j) != dp.end() ? dp[s[i]+j] : 0;
                    mx = max(mx, count);
                }
                if(s[i] - j >= 'a'){
                    int count = dp.find(s[i]-j) != dp.end() ? dp[s[i]-j] : 0;
                    mx = max(mx, count);
                }
            }
            dp[s[i]] = max(mx, prev) + 1;
        }
        int x = 0;
        for(auto it: dp){
            x = max(x, it.second);
        }
        return x;
    }
};