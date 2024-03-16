class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            
            if(stops > k)
                break;
            for(auto edge: adj[node]){
                int adjnode = edge.first;
                int adjwt = edge.second;
                
                if(dis + adjwt < dist[adjnode] && stops <= k){
                    dist[adjnode] = dis + adjwt;
                    q.push({stops+1, {adjnode, dis+adjwt}});
                }
            }
        }
        
        if(dist[dst] == 1e9)
            return -1;
        
        return dist[dst];
    }
};