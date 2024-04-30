class Solution {
public:
    map<array<int, 4>, int> m;
    vector<vector<int>> g;
    int cherryPickup(vector<vector<int>>& grid) {
        g = grid;
        return max(0, dfs({0,0,0,0}));
    }
    
    int dfs(array<int, 4> a){
        int x1 = a[0], y1 = a[1], x2 = a[2], y2 = a[3];

        if (x1 == g.size() - 1 && y1 == g[0].size() - 1)
            return g[x1][y1] > 0;

        if (x1 == g.size() || x2 == g.size() || y1 == g[0].size() || y2 == g[0].size() || g[x1][y1] == -1 || g[x2][y2] == -1)
            return INT_MIN;

        if (m.count(a)) return m[a];

        int ans = INT_MIN; 
        ans = max(ans, dfs({x1 + 1, y1, x2 + 1, y2}));
        ans = max(ans, dfs({x1 + 1, y1, x2, y2 + 1}));
        ans = max(ans, dfs({x1, y1 + 1, x2 + 1, y2}));
        ans = max(ans, dfs({x1, y1 + 1, x2, y2 + 1}));

        return m[a] = ans + g[x1][y1] + g[x2][y2] - (x1 == x2 && y1 == y2 && g[x1][y1]);
    }
};