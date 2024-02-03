class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        for(int i = n-1; i >= 0; i--){
            int len = 0, maxi = INT_MIN, ans = INT_MIN;
            for(int j = i; j < min(n, i+k); j++){
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j+1];
                ans = max(sum, ans);
            }
            dp[i] = ans;
        }

        return dp[0];
    }
};