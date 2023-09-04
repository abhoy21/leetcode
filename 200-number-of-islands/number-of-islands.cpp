class Solution {
public:
    void calc(vector<vector<char>>& grid, int i, int j)
    {

        if(i < 0 || j < 0 || i >=grid.size() || j >= grid[0].size())
            return;
        
        if(grid[i][j] == '0')
            return;
        grid[i][j] = '0';

        calc(grid, i+1, j);
        calc(grid, i, j+1);
        calc(grid, i-1, j);
        calc(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    calc(grid,i,j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};