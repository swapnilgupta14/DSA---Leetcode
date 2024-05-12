class Solution {
private:
    int traverse(int i, int j, vector<vector<int>>& grid) {
        int maxi = 0;
        for (int l = i; l < i + 3; l++) {
            for (int m = j; m < j + 3; m++) {
                if (grid[l][m] > maxi)
                    maxi = grid[l][m];
            }
        }
        return maxi;
    }

public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int m = traverse(i, j, grid);
                ans[i][j] = m;
            }
        }

        return ans;
    }
};
