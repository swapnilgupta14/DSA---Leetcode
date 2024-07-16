class Solution {
    stack<int> st;

private:
    bool dfs(int i, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj) {
        vis[i] = 1;
        pathVis[i] = 1;

        for (int it : adj[i]) {
            if (!vis[it]) {
                if (!dfs(it, vis, pathVis, adj))
                    return false;
            } else if (pathVis[it]) {
                return false;
            }
        }

        st.push(i);
        pathVis[i] = 0;
        return true;
    }

public:
    vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(v);

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(v, 0);
        vector<int> pathVis(v, 0);
        vector<int> result;

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (!dfs(i, vis, pathVis, adj))
                    return {};
            }
        }

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};