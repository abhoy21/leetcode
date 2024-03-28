class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int s = 0, ans = 0;
        for(int e = 0; e < nums.size(); e++){
            mp[nums[e]]++;
            while(mp[nums[e]] > k){
                mp[nums[s]]--;
                s++;
            }
            ans = max(ans, e - s + 1);
        }

        return ans;
    }
};