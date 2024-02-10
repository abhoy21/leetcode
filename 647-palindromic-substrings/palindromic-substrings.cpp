class Solution {
public:

    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int count = 0;
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j ++){
                if(i == j)
                    dp[i][j] = 1;
                else if(i+1 == j)
                    dp[i][j] = s[i] == s[j] ? 1 : 0;
                else
                    dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] : 0;
                count += dp[i][j];
            }
        }

        return count;

    }
};