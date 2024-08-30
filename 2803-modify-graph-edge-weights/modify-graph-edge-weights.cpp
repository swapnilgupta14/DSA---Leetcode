class Solution {
public:
    int dijkstra(int src, vector<vector<pair<int, int>>>& adj, int n, int dest) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        long kMax = 2e9;
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (w != -1) {
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
        }

        int init = dijkstra(source, adj, n, destination);

        if (init < target)
            return {};

        if (init == target) {
            for (auto& e : edges) {
                if (e[2] == -1)
                    e[2] = kMax;
            }
            return edges;
        }

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            int& w = edges[i][2];
            if (w != -1)
                continue;
            
            w = 1;
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});

            int dist = dijkstra(source, adj, n, destination);

            if (dist <= target) {
                w += (target - dist);
                for (int j = i + 1; j < edges.size(); j++) {
                    if (edges[j][2] == -1)
                        edges[j][2] = kMax;
                }
                return edges;
            }
        }

        return {}; 
    }
};