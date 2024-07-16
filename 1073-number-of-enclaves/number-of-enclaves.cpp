class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &vis ){
        vis[i][j] = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> dir = {{0, 1}, {1, 0},  {0, -1}, {-1, 0}};
        
        for(auto it: dir){
            int nx = i + it.first;
            int ny = j + it.second;
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] == 1){
                vis[nx][ny] = 0;
                dfs(nx, ny, grid, vis);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vis[i][j] = grid[i][j];
            }
        }

        for(int i= 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || i == n-1){
                    if(grid[i][j] == 1){
                        dfs(i, j, grid, vis);
                    }
                }
                else if((i !=0 && i != n-1) && (j == 0 || j == m-1)){
                    if(grid[i][j] == 1){
                        dfs(i, j, grid, vis);
                    }
                }
            }
        }

        int count = 0;
        for(auto it : vis){
            for(int jt: it) if(jt == 1) count+=1;
        }

        return count;
    }
};