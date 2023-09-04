class Solution {
public:
    bool check(vector<vector<int>>& grid, int i, int j)
    {
        if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == 1)
            return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, time = 0;
         for(int i = 0; i < m; i++)
         {
             for(int j = 0; j < n; j++)
             {
                if(grid[i][j] == 1)
                    fresh++;
                if(grid[i][j] == 2)
                    q.push({i,j});
             }
         }

         if(fresh == 0) return 0;

         while(!q.empty())
         {
             int size = q.size();
             int temp = 0;
             while(size--)
             {
                 int x1 = q.front().first;
                 int y1 = q.front().second;
                 q.pop();
                 int a[4] = {1,-1,0,0};
                 int b[4] = {0,0,1,-1};
                 for(int i = 0; i < 4; i++)
                 {
                     int x = x1 + a[i];
                     int y = y1 + b[i];
                     if(check(grid,x,y))
                     {
                         temp++;
                         grid[x][y] = 2;
                         q.push({x,y});
                     }
                 }
             }
             if(temp != 0) time++;
         }

         for(int i = 0; i < m; i++)
         {
             for(int j = 0; j < n; j++)
             {
                 if(grid[i][j] == 1)
                    return -1;
             }
         }

         return time;

    }
};