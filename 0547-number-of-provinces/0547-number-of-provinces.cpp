class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int>& visited) {
        visited[node] = 1;
        for(int neighbour : adj[node]) {
            if(!visited[neighbour]) {
                dfs(neighbour, adj, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> visited(n, 0);
        int count = 0;
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};