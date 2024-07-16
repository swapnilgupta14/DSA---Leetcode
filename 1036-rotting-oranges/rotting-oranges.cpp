class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = grid[i][j];
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        int count = 0;

        while (!q.empty()) {
            int qs = q.size();
            for (int i = 0; i < qs; i++) {
                auto fr = q.front();
                q.pop();

                auto first = fr.first;
                auto second = fr.second;
                count = second;

                vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

                for (auto dir : directions) {
                    int nx = first.first + dir.first;
                    int ny = first.second + dir.second;

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && vis[nx][ny] != 2) {
                        vis[nx][ny] = 2;
                        q.push({{nx, ny}, second + 1});
                    }
                }
            }
        }

        for(auto it: vis){
            for(auto jt: it){
                if(jt == 1) return -1;
            }
        }

        return count;
    }
};