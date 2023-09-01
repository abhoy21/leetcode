class Solution {
public:
    void floodFillDFS(vector<vector<int>>& image, int r, int c, int oc, int nc) {
        if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size() || image[r][c] != oc)
            return;

        image[r][c] = nc;

        floodFillDFS(image, r - 1, c, oc, nc);
        floodFillDFS(image, r + 1, c, oc, nc);
        floodFillDFS(image, r, c - 1, oc, nc);
        floodFillDFS(image, r, c + 1, oc, nc);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];

        if (originalColor != newColor) {
            floodFillDFS(image, sr, sc, originalColor, newColor);
        }

        return image;
    }
};
