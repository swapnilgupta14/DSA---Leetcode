class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();

        int m1=INT_MAX,m2=INT_MAX;
        for(int i=0;i<n;i++){
            if(m1 < m2){
                m2=min(m2,grid[0][i]);
            }else{
                m1=min(m1,grid[0][i]);
            }
        }
        for(int i=1;i<n;i++){
            int t1=INT_MAX,t2=INT_MAX;

            for(int j=0;j<n;j++){
                if(grid[i-1][j]!=m1 && grid[i-1][j]!=m2)grid[i][j]+=min(m1,m2);
                else if(grid[i-1][j]==m1){
                    grid[i][j]+=m2;
                }else{
                    grid[i][j]+=m1;
                }

                if(t1 < t2){
                    t2=min(t2,grid[i][j]);
                }else{
                    t1=min(t1,grid[i][j]);
                }
            }
            m1=t1;
            m2=t2;
        }
        return min(m1,m2);
    }
};

class Solution_Backtracking {
// Backtracking - TLE - 6/16 code passes 
private:
    void helper(vector<vector<int>>& grid, int &sum, int i, int j, int &row, int &col){
        if(i >= row || j >= col || j < 0 || i < 0) return;
        sum += grid[i][j];
        if (i == row - 1) {
            return;
        }
        int min_sum = INT_MAX;
        for (int it = 0; it < col; it++) {
            if (it != j) {
                int temp_sum = sum;
                helper(grid, temp_sum, i + 1, it, row, col);
                min_sum = min(min_sum, temp_sum);
            }
        }
        sum = min_sum;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int min_sum = INT_MAX;
        for (int j = 0; j < col; j++) {
            int sum = 0;
            helper(grid, sum, 0, j, row, col);
            min_sum = min(min_sum, sum);
        }
        return min_sum;
    }
};
