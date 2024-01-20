class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size(), maxi = 1;
        vector<int> dp(n, 1);

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                dp[i] += dp[i-1];
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};