class Solution {
private:
    void func(int i, int j, vector<vector<char>>& grid,
              vector<vector<int>>& vis, int n, int m) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            int row, col;
            tie(row, col) = q.front();
            q.pop();

            // Check for horizontal and vertical movements only
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            for (int d = 0; d < 4; d++) {
                int nrow = row + dr[d];
                int ncol = col + dc[d];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    ans++;
                    func(i, j, grid, vis, n, m);
                }
            }
        }

        return ans;
    }
};