class Solution {
public:
    int mod = 1e9+7;
    int kInversePairs(int n, int k) {
       // Initialize a 2D vector to store the dynamic programming results
        // dp[i][j] represents the number of arrays with i elements and j inverse pairs
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        // Base case: For every value of k where k is 0, the answer is 1
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;


        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                // Calculate the total number of arrays with i elements and j inverse pairs
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;

                // If j - i is greater than or equal to 0, consider the contribution from arrays with (i-1)(j-i) elements as theanswer will only have the value that was stored in (i-1)(j-i)th position
                if (j - i >= 0)
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + mod ) % mod;
            }
        }

        // Return the final result representing the number of arrays with n elements and k inverse pairs
        return dp[n][k];
    }
};