class Solution {
public:
    int func(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i < 0)
            return j + 1;
        if(j < 0)
            return i + 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s2[j])
            return dp[i][j] = func(i-1, j-1, s1, s2, dp);
        return dp[i][j] = 1 + min(func(i-1, j, s1, s2, dp), 
        min(func(i, j-1, s1, s2, dp), func(i-1,j-1, s1, s2, dp))); 
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(n-1, m-1, word1, word2, dp);
    }
};