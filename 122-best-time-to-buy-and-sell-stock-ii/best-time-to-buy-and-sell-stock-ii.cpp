//recursion
class Solution {
private:
    int fun(int ind,int buy,int n,vector<int>& prices, vector<vector<long>> &dp){
        if(ind >= n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        long profit = 0;
        if(buy){
            int take = -1 * prices[ind]+ fun(ind+1,0,n,prices, dp);
            int notTake = fun(ind+1,1,n,prices, dp);
            profit = max(take, notTake);
        }
        else{
            int take= prices[ind]+ fun(ind+1,1,n,prices, dp);
            int notTake= fun(ind+1,0,n,prices, dp);
            profit = max(take,notTake);
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<long>> dp(n, vector<long>(2, -1));
        return fun(0,1,n,prices, dp);
    }
};