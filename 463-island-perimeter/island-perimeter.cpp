class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;

                    if (i - 1 >= 0 && grid[i - 1][j] == 1) perimeter--; 
                    if (i + 1 < rows && grid[i + 1][j] == 1) perimeter--;
                    if (j - 1 >= 0 && grid[i][j - 1] == 1) perimeter--; 
                    if (j + 1 < cols && grid[i][j + 1] == 1) perimeter--; 
                }
            }
        }
        return perimeter;
    }
};
