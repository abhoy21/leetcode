class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int cap = 3; cap >= 0; cap--) {
                if (cap % 2 == 0)
                    dp[i][cap] = max(-prices[i] + dp[i + 1][cap + 1],
                                     0 + dp[i + 1][cap]);
                else
                    dp[i][cap] =
                        max(prices[i] + dp[i + 1][cap + 1], 0 + dp[i + 1][cap]);
            }
        }

        return dp[0][0];
    }
};