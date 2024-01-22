class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int>mp;
        int n = nums.size();
        for(int i = 1; i <= n; i++)
            mp[i]++;
        for(int n : nums)
            mp[n]--;
        int dup = 0, mis = 0;
        for(auto v : mp){
            if(v.second == -1)
                dup = v.first;
            if(v.second == 1)
                mis = v.first;
        }

        return {dup, mis};
    }
};