class Solution {
public:
    int func(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int cnt = 0, i = 0, j = 0;
        while(j < nums.size()){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            cnt += j - i + 1;
            j++;
        }

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k-1);
    }
};