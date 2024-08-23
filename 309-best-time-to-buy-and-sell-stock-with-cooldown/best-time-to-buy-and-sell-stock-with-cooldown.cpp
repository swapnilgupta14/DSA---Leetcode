class Solution {
private:
    int helper(int i, int buy, vector<int> &prices, int n, vector<vector<int>> &dp){
        if(i >= n) return 0;
        int profit = 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy == 1){
            int buy = prices[i] * -1 + helper(i+1, 0, prices, n, dp);
            int ignore = helper(i+1, 1, prices, n, dp);
            profit = max(buy, ignore);
        }else if(buy == 0){
            int sell = prices[i] + helper(i+1, 2, prices, n, dp);
            int ignore = helper(i+1, 0, prices, n, dp);
            profit = max(sell, ignore);
        }else if(buy == 2){
            profit = helper(i+1, 1, prices, n, dp);
        }
        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        int x = helper(0, 1, prices, n, dp);
        return x ;
    }
};