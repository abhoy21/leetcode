class Solution {
public:
 unordered_map<int, int> mp;
    void func(vector<int>& nums, int k, int& ans, int idx){
        if(idx == nums.size()){
            ans++;
            return;
        }
        int num = nums[idx];
        if(mp.find(num-k) == mp.end() && mp.find(num+k) == mp.end()){
            mp[num]++;
            func(nums, k, ans, idx+1);
            mp[num]--;
            if(mp[num] == 0)
                mp.erase(num);
        }

        func(nums, k, ans, idx+1);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        func(nums,k, ans, 0);

        return ans-1;
    }
};