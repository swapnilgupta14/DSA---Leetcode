class Solution {
private:
    void dfs(int i, vector<int> &vis, vector<vector<int>> &adj) {
        if (vis[i] == 1) return;
        vis[i] = 1;
        for(auto it: adj[i]){
            if(!vis[it]) dfs(it, vis, adj);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // creating adjacency matrix
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }
        int count = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (vis[i] != 1) {
                count += 1;
                dfs(i, vis, adj);
            }
        }
        return count;
    }
};