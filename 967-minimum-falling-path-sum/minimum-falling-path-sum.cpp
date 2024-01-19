class Solution {
public:
    // int f(int i,int j,int n,int m,vector<vector<int>>& a,vector<vector<int>>&dp)
    // {
    //     if(j<0 || j>m-1)
    //         return 1e9;
        
    //     if(i==0)
    //         return a[i][j];
        
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
        
    //     int up = a[i][j] + f(i-1,j,n,m,a,dp);
        
    //     int ld = a[i][j] + f(i-1,j-1,n,m,a,dp);
        
    //     int rd = a[i][j] + f(i-1,j+1,n,m,a,dp);
        
        
    //     return dp[i][j]=min(up,min(ld,rd));
        
    // }
    
    
    // int minFallingPathSum(vector<vector<int>>& matrix) {
        
    //     int ans=INT_MAX;
        
    //     int n=matrix.size();
        
    //     int m=matrix[0].size();
        
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
        
    //     for(int j=0;j<m;j++)
    //     {
    //         ans=min(ans,f(n-1,j,n,m,matrix,dp));
    //     }
        
    //     return ans;
        
    // }

     int minFallingPathSum(vector<vector<int>>& matrix) {
        
        
        
        int n=matrix.size();
        
        int m=matrix[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        
        for(int j=0;j<m;j++)
        {
            dp[0][j]=matrix[0][j];
            
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ld=1e9,rd=1e9;
                
                
                int up=matrix[i][j] + dp[i-1][j];
                
                if(j-1>=0)
                    ld=matrix[i][j] + dp[i-1][j-1];
                if(j+1<m)
                    rd=matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j] = min(up,min(ld,rd));
                
                
                
            }
        }
        
        int mini=dp[n-1][0];
        
        for(int j=1;j<m;j++)
        {
            
            mini=min(mini,dp[n-1][j]);
            
        }
        return mini;
        
    }

};