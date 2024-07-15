class Solution {
private:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, int i) {
        vis[i] = 1;
        pathVis[i] = 1;

        for (auto it : adj[i]) {
            if (!vis[it]) {
                if(!dfs(adj, vis, pathVis, it)) return false;
            }
            else if (pathVis[it]) {
                return false;
            }
        }
        pathVis[i] = 0;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // [ai, bi]
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] != 1) {
                if (dfs(adj, vis, pathVis, i) == false) return false;
            }
        }
        return true;
    }
};