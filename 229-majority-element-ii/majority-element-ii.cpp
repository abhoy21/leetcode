class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int target = nums.size()/3;
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto num: nums)
            mp[num]++;

        for(auto num : nums){
            if(mp[num] > target){
                ans.push_back(num);
                mp[num] = 0;
            }
        }    
        return ans;
    }
};