class Solution {
public:
    bool calc(vector<vector<int>>& grid, int i, int j, int& cnt)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return 0;
        if(grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        if(calc(grid,i+1,j,cnt)) cnt++; // checking if it is 1 or not
        if(calc(grid,i-1,j,cnt)) cnt++;
        if(calc(grid,i,j+1,cnt)) cnt++;
        if(calc(grid,i,j-1,cnt)) cnt++;

        return 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int cnt, maxarea = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                cnt = 1;
                if(grid[i][j] == 1)
                {
                    calc(grid, i, j, cnt);
                    maxarea = max(maxarea, cnt);
                } 
            }
        }

        return maxarea;
    }
};