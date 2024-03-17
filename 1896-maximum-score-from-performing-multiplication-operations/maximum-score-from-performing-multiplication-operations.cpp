class Solution {
public:
    int f(int i, int s, vector<int>& nums, vector<int>& multi, int n, int m,
          vector<vector<int>>& dp) {
        if (i == m)
            return 0;
        if (dp[i][s] != -1)
            return dp[i][s];
        int start = multi[i] * nums[s] + f(i + 1, s + 1, nums, multi, n, m, dp);
        int end = multi[i] * nums[(n - 1) - (i - s)] +
                   f(i + 1, s, nums, multi, n, m, dp);
        return dp[i][s] = max(start, end);
    }

    int maximumScore(vector<int>& nums, vector<int>& multi) {
        int n = nums.size();
        int m = multi.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return f(0, 0, nums, multi, n, m, dp);
    }
};