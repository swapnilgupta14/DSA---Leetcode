#include <vector>

class Solution {
private:
    bool dfs(int i, vector<vector<int>>& graph, int n, vector<int>& color, vector<int>& vis, int change) {
        if (color[i] == change) {
            return false;
        }
        vis[i] = 1;
        color[i] = change;
        for (int it : graph[i]) {
            if (vis[it] != 1) {
                if (!dfs(it, graph, n, color, vis, !change)) return false;
            } else if (color[it] == color[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        vector<int> vis(n, 0);

        for (int i = 0; i < n; ++i) {
            if (vis[i] != 1) {
                if (!dfs(i, graph, n, color, vis, 0)) {
                    return false;
                }
            }
        }

        return true;
    }
};
