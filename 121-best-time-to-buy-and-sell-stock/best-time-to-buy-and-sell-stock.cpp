class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0];
        int max_profit = 0;

        for(int i=1; i<prices.size(); i++){
            int cost = prices[i] - m;
            max_profit = max(max_profit, cost); 
            if(prices[i] < m) m = prices[i];
        }

        return max_profit;
    }

    int maxProfit_brute(vector<int>& prices) {
        // brute force - T.L.E - 202/212 passed 
        int n = prices.size();
        int m = INT_MIN;
        for(int i=n-1; i>= 1; i--){
            for(int j = i-1; j>= 0; j--){
                int price = prices[i] - prices[j];
                if(price> 0 && price > m) m = price;
            }
        }

        if(m > INT_MIN) return m;
        return 0;
    }
};