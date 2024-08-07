class Solution {
private:
    int helper(int i, int buy, vector<int>& prices, int limit, vector<vector<vector<int>>> &dp) {
        int n = prices.size();
        
        // Base case: no days left or no transactions left
        if (i >= n || limit == 0) return 0;
        
        // Check if the state has already been computed
        if (dp[i][buy][limit] != -1) return dp[i][buy][limit];
        
        int profit = 0;
        if (buy) {
            // Option 1: Buy stock
            int a = -prices[i] + helper(i + 1, 0, prices, limit, dp);
            // Option 2: Skip buying
            int b = helper(i + 1, 1, prices, limit, dp);
            profit = max(a, b);
        } else {
            // Option 1: Sell stock
            int a = prices[i] + helper(i + 1, 1, prices, limit - 1, dp);
            // Option 2: Skip selling
            int b = helper(i + 1, 0, prices, limit, dp);
            profit = max(a, b);
        }
        
        return dp[i][buy][limit] = profit;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // DP table with dimensions (n, 2, k + 1)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return helper(0, 1, prices, k, dp);
    }
};
