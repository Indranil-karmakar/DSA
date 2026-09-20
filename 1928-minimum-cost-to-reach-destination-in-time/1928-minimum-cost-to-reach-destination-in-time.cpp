class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
        > pq;
        int n = passingFees.size();
        vector<vector<pair<int, int>>> adj(n);
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        vector<vector<int>> dis(n, vector<int>(maxTime + 1, INT_MAX));
        dis[0][0] = passingFees[0];
        pq.push({passingFees[0], 0, 0});
        while(!pq.empty()) {
            auto [cost, time, city] = pq.top();
            pq.pop();

            // If we reached destination,
            // because PQ is ordered by cost,
            // this is the minimum cost.
            if(city == n - 1) {
                return cost;
            }
            for(auto [neighbour, roadtime]: adj[city]) {
                int newtime = time + roadtime;
                if(newtime > maxTime) {
                    continue;
                }
                int newcost = cost + passingFees[neighbour];
                if(newcost < dis[neighbour][newtime]) {
                    dis[neighbour][newtime] = newcost;
                    pq.push({newcost, newtime, neighbour});
                }
            }
        }
        return -1;
    }
};