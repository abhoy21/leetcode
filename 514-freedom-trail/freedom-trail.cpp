class Solution {
public:
    int dfs(int index, int pos, int n, int m, unordered_map<char, vector<int>>& adj, string &key, vector<vector<int>>& dp){
        if(index >= m)
            return 0;
        if(dp[index][pos] != -1)
            return dp[index][pos];

        int min_steps = INT_MAX;

        for(auto it: adj[key[index]]){
            int steps;

            if(it >= pos){
                steps = min(it - pos, pos + n - it);
            }
            else {
                steps = min(pos - it, it + n - pos);
            }

            min_steps = min(min_steps, (steps + dfs(index + 1, it, n, m, adj, key, dp)));
        }

        return dp[index][pos] = min_steps + 1;
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        unordered_map<char, vector<int>> adj;

        for(int i = 0; i < n; i++){
            adj[ring[i]].push_back(i);
        }

        vector<vector<int>> dp(m + 1, vector<int>(n+1, -1));
        return dfs(0, 0, n, m, adj, key, dp);
    }
};