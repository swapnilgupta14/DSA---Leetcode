class Solution {
    const int mod = 1e9 + 7;
    int dp[100001][2][3];
    int find(int n,int a,int l) {
        if(n==0) return 1;
        if(dp[n][a][l]!=-1) return dp[n][a][l];
        int ans = find(n-1,a,0)%mod;
        if(a==0) {
            ans += find(n-1,a+1,0)%mod;
            ans %= mod;
            if(l<=1) ans += find(n-1,a,l+1)%mod;
        }
        else {
            if(l<=1) ans += find(n-1,a,l+1)%mod;
        } 
        return dp[n][a][l] = ans%mod;
    }
public:
    int checkRecord(int n) {
        for(int i=0; i<100001; i++) {
            for(int j=0; j<2; j++) {
                for(int k=0; k<3; k++) dp[i][j][k] = -1;
            }
        }
        return find(n,0,0);
    }
};