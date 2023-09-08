class Solution {
public:
    bool check(vector<int>& nums, int sum, int i, vector<vector<int>>& dp)
    {
        if(sum == 0)
            return true;
        
        if(i == 0) return (nums[0] == sum);

        if(dp[i][sum] != -1)
            return dp[i][sum];

        bool notTake = check(nums, sum, i -1, dp);
        bool take = false;

        if(nums[i] <= sum)
            take = check(nums, sum - nums[i], i - 1, dp);

        return dp[i][sum] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        for(int i = 0; i < nums.size(); i++)
            totalsum += nums[i];

        if(totalsum % 2 != 0)
            return false;
        int k = totalsum / 2;
        vector<vector<int>> dp(nums.size()+1, vector<int>(k+1, -1));
        return check(nums, totalsum/2, nums.size()-1, dp);
        
    }
};