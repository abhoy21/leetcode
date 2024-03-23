class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {


        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++)
            adj[i][i] = 0;

        for(int i = 0; i < edges.size(); i++){
            int src = edges[i][0];
            int dst = edges[i][1];
            int wt = edges[i][2];

            adj[src][dst] = wt;
            adj[dst][src] = wt;
        }
        int cnt = 0, maxval = n, ans = 0;
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(adj[i][k] + adj[k][j] <= distanceThreshold){
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            cnt = 0;
            for(int j = 0; j < n; j++){
                if(i != j && adj[i][j] <= distanceThreshold)
                    cnt++;
            }
            if(cnt <= maxval){
                maxval = cnt;
                ans = i;
            }
        }

        return ans;
    }
};