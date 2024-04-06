class Solution {
private:
    int timer = 1;
private:
    void dfs(vector<int> adj[], vector<int> &vis, vector<vector<int>> &bridges, int tin[], int low[], int node, int parent){
        vis[node] = 1;
        low[node] = tin[node] = timer++;

        for(auto it: adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(adj, vis, bridges, tin, low, it, node);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node])
                    bridges.push_back({node, it});
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> bridges;
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        dfs(adj, vis, bridges, tin, low, 0, -1);

        return bridges;
    }
};