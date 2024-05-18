class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m, int i,int j){
        vis[i][j] = 1;

        int dr[] = {0, 1, 0, -1};
        int dc[] = {-1, 0, 1, 0};

        for(int k = 0; k < 4; k++){
            int newi = i + dr[k];
            int newj = j + dc[k];
           if (newi >= 0 && newi < n && newj >= 0 && newj < m) {
                if (!vis[newi][newj] && grid[newi][newj] == '1')
                    dfs(grid, vis, n, m, newi, newj);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(grid, vis, n, m, i, j);
                }
            }
        }

        return cnt;
    }
};