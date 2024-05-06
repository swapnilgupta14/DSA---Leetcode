class Solution {
private:
    void dfs(int i, vector<int> &vis, vector<int> adjList[]){
        vis[i] = 1;
        for(auto it: adjList[i]){
            if(vis[it] == 0)
                dfs(it, vis, adjList);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjList[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count += 1;
                dfs(i, vis, adjList);
            }
        }
        return count;
    }
};