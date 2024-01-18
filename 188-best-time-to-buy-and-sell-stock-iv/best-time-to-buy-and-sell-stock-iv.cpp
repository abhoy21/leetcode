class Solution {
private:
    int func(int i, int tran, int k, vector<int>& prices, int n,
             vector<vector<int>>& dp) {
        if (i == n || tran == 2 * k)
            return 0;
        if (dp[i][tran] != -1)
            return dp[i][tran];
        if (tran % 2 == 0)
            return dp[i][tran] =
                       max(-prices[i] + func(i + 1, tran + 1, k, prices, n, dp),
                           0 + func(i + 1, tran, k, prices, n, dp));
        return dp[i][tran] =
                   max(prices[i] + func(i + 1, tran + 1, k, prices, n, dp),
                       0 + func(i + 1, tran, k, prices, n, dp));
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));

        return func(0, 0, k, prices, n, dp);
    }
};