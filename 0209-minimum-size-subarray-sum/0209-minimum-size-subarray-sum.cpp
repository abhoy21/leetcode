class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0, sum = 0;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while( sum >= target)
            {
                ans = min(ans, i-j+1);
                sum -= nums[j];
                j++;
            }

        }

        return ans == INT_MAX ? 0 : ans;
    }
};