class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int, int> mp;
        long long sum = 0, ucount = 0, ans = 0;

        for(int i = 0, j = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]] == 1)
                ucount++;
            if(i >= k)
            {
                sum -= nums[j];
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    ucount--;
                j++;
            }
            if(ucount >= m)
                ans = max(ans, sum);
        }

        return ans;
    }
};