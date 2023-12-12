class Solution {
public:
int findMaxIndex(vector<vector<int>>& mat, int m, int n, int col){
    int maxVal = -1;
    int index = -1;
    for(int i = 0; i < m; i++){
        if(mat[i][col] > maxVal){
            maxVal = mat[i][col];
            index = i;
        }
    }

    return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0, high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int maxrow = findMaxIndex(mat, m, n, mid);
            int left = mid - 1 >= 0 ? mat[maxrow][mid - 1] : -1;
            int right = mid + 1 < n ? mat[maxrow][mid + 1] : -1;
            if(mat[maxrow][mid] > left && mat[maxrow][mid] > right){
                return {maxrow, mid};
            }
            else if( mat[maxrow][mid] < left){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};