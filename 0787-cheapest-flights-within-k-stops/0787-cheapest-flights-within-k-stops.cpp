class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, pair<int,int>>> q;
        vector<pair<int, int>> adj[n];
        for(auto it: flights) {
            adj[it[0]].push_back({it[1], it[2]});

        }

        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(steps > k) continue;
            for(auto iter: adj[node]) {
                int adjNode = iter.first;
                int edgeWeight = iter.second;
                if(cost + edgeWeight < dist[adjNode] && steps <= k) {
                    dist[adjNode] = cost + edgeWeight;
                    q.push({steps + 1,{adjNode, cost + edgeWeight}});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};