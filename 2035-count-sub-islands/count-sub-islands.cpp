static constexpr bool inRange(int x, int y, const int m, const int n) {
    return x >= 0 && y >= 0 && x < m && y < n;
}

void bfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<bool>& visited, bool& isSubIsland, int m, int n) {
    visited[i * n + j] = true;
    assert(grid2[i][j] == 1);
    if (grid1[i][j] == 0) {
        isSubIsland = false;
    }

    static constexpr auto directions = array<pair<int, int>, 4>{
        pair<int, int>{0, 1}, pair<int, int>{0, -1}, pair<int, int>{-1, 0}, pair<int, int>{1, 0}
    };

    for (const auto& [dx, dy] : directions) {
        int x = i + dx;
        int y = j + dy;
        if (!inRange(x, y, m, n)) {
            continue;
        }
        if (visited[x * n + y]) {
            continue;
        }
        if (grid2[x][y] == 0) {
            continue;
        }

        bfs(x, y, grid1, grid2, visited, isSubIsland, m, n);
    }
}

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        const int m = static_cast<int>(grid1.size());
        const int n = static_cast<int>(grid1[0].size());
        auto visited = vector<bool>(m * n, false);
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i * n + j]) {
                    continue;
                }
                if (grid2[i][j] == 0) {
                    continue;
                }
                bool isSubIsland = true;

                bfs(i, j, grid1, grid2, visited, isSubIsland, m, n);

                if (isSubIsland) {
                    ans += 1;
                }
            }
        }

        return ans;
    }
};