class Solution {
private:
    bool dfs(int i, vector<vector<int>>& graph, int n, vector<int> &safeNodes, vector<int> &vis, vector<int> &pathVis){
        vis[i] = 1;
        pathVis[i] = 1;

        for(int it: graph[i]){
            if(vis[it] != 1){
                if(!dfs(it, graph, n, safeNodes, vis, pathVis)) return false;
            }
            else if(pathVis[it] == 1) return false;
        }

        pathVis[i] = 0;
        safeNodes[i] = 1;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> safeNodes(n, 0);
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);

        for(int i=0; i<n; i++){
            if(vis[i] != 1){
                dfs(i, graph, n, safeNodes, vis, pathVis);
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(safeNodes[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};