class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int min = prices[0];
        int m = 0;

        for(int i=0; i<n-1; i++){
            if(prices[i] < prices[i+1]){
                m += (prices[i+1] - prices[i]);
            }
        }

        return m;
    }
};