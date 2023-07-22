class Solution {
    
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>rm(n,1);
        vector<int>cm(m,1); 
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    rm[i] = 0;
                    cm[j] = 0;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m;j++)
            {
                if(rm[i]==0 || cm[j]==0)
                    matrix[i][j] = 0;
            }
        }
        
    }
};