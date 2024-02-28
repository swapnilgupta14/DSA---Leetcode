class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> ad(n);
        vector<int> dist(n,INT_MAX);

        for(auto &v : flights){
            ad[v[0]].push_back({v[1],v[2]});
        }

        // <stops, curr node, cost>
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int curr = it.second.first;
            int cost = it.second.second;

            if(stops>k) continue;

            for(auto &city : ad[curr]){
                if(cost+city.second < dist[city.first]){
                    q.push({stops+1,{city.first,cost+city.second}});
                    dist[city.first] = cost+city.second;
                }
            }
        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};