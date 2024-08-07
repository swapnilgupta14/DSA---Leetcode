class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // [7,1,5,3,6,4]
        // 7 -> 7;
        // 1 -> 7;
        // 5 -> 5;
        // 3 -> 1;
        int n = prices.size();
        int min = prices[0];
        int m = INT_MIN;
        for(int i=0; i<n; i++){
            if(prices[i] < min) min = prices[i];
            m = max(m, prices[i] - min);
        }

        return m;

    }
};