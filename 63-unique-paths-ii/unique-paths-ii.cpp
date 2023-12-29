class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0);
        for(int i = 0; i < m; i++){
            vector<int> cur(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0 && obstacleGrid[i][j] != 1)
                    cur[j] = 1 ;
                else if(obstacleGrid[i][j] == 1)
                    cur[j] = 0;
                else{
                    int down = 0, right = 0;
                    if(i > 0)
                        down = obstacleGrid[i][j] + prev[j];
                    if(j > 0)
                        right = obstacleGrid[i][j] + cur[j-1];
                    
                    cur[j] = down + right;
                }
            }
            prev = cur;
        }

        return prev[n-1];
    }
};