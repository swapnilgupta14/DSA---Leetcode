class Solution {
private:
    int helper(int i, int buy, vector<int>& prices, int limit, vector<vector<vector<int>>> &dp){
        int n = prices.size();

        if( i >= n || limit == 0) return 0;
        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];

        int profit = 0;
        if(buy){
            int a = prices[i] * -1  + helper(i + 1, 0, prices, limit, dp);
            int b = helper(i+1, 1, prices, limit, dp);
            profit = max(a, b);
        }else{
            int a = prices[i]  + helper(i + 1, 1, prices, limit - 1, dp);
            int b = helper(i+1, 0, prices, limit, dp);
            profit = max(a, b);
        }

        return dp[i][buy][limit] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(k+1, -1)));
        return helper(0, 1, prices, k, dp);
    }
};
