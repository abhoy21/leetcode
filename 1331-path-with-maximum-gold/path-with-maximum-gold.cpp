class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m, int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || vis[i][j] == 1)
            return 0;

        vis[i][j] = 1;
        int ans = grid[i][j];
        int dr[] = {0, 1, 0, -1};
        int dc[] = {-1, 0, 1, 0};

        for(int k = 0; k < 4; k++){
            int newi = i + dr[k];
            int newj = j + dc[k];
            
            ans = max(ans, grid[i][j] + dfs(grid, vis, n, m, newi, newj));
        }
        
        vis[i][j] = 0; 
        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0) {
                    maxans = max(maxans, dfs(grid, vis, n, m, i, j));
                }
            }
        }
        
        return maxans;
    }
};
