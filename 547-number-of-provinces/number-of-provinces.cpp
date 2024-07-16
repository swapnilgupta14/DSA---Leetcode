class Solution {
private:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis){
        if(vis[i]){
            return;
        }
        vis[i] = 1;

        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int s = isConnected.size();
        vector<vector<int>> adj(s);
        for(int i=0; i<s; i++){
            for(int j=0; j<s; j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(s, 0);
        int count = 0;
        for(int i=0; i<s; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                count ++;
            }
        }

        return count;

    }
};