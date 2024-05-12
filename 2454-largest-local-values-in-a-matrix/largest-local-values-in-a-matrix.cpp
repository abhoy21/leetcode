class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2, 0));
        for(int i = 0; i < n-2; i++){
            for(int j = 0; j < grid[0].size()-2; j++){
                for(int a = i; a < i+3; a++){
                    for(int b = j; b < j+3; b++){
                        ans[i][j] = max(ans[i][j], grid[a][b]);
                    }
                }
            }
        }

        return ans;
    }
};