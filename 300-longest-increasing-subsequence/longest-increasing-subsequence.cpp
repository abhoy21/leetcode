class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i])
                    dp[i] = max(dp[i], dp[prev] + 1);
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};