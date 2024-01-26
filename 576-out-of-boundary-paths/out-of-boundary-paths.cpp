class Solution {
public:
    int mod = 1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[startRow][startColumn] = 1;
        int count = 0;
        while(maxMove--){
            vector<vector<int>> temp(m, vector<int>(n,0));
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(dp[i][j] > 0){
                        for(auto& [dx,dy]: dirs){
                            int x = i + dx;
                            int y = j + dy;

                            if(x < 0 || x == m || y < 0 || y == n)
                                count = (count + dp[i][j]) % mod; 
                            else
                                temp[x][y] = (temp[x][y] + dp[i][j]) % mod; 
                        }
                        
                    }
                }
            }
            dp = temp;
        }

        return count;

    }
};