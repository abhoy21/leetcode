class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1, lastind = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            hash[i] = i;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastind = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastind]);
        while(hash[lastind] != lastind){
            lastind = hash[lastind];
            ans.push_back(nums[lastind]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};