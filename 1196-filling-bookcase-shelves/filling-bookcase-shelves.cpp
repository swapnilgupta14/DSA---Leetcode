#define WIDTH 0
#define HEIGHT 1
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1, 0);

        for(int i=1 ; i<=n ; i++)
        {
            dp[i] = dp[i-1] + books[i-1][HEIGHT];
            int height = books[i-1][HEIGHT];
            int width = books[i-1][WIDTH];
            for(int j=i-1 ; j>0 ; j--)
            {
                if(width + books[j-1][WIDTH] > shelfWidth) break;
                height = max(height, books[j-1][HEIGHT]);
                width += books[j-1][WIDTH];
                dp[i] = min(dp[i], height + dp[j-1]);
            }
        }
        return dp[n];
    }
};