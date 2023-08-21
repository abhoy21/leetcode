class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> check;

        for(int i = 0; i < nums.size(); i++)
        {
            if(check.find(target-nums[i])!=check.end())
                return {i, check[target-nums[i]]};
            check[nums[i]] = i;
        }
        
        return {0,0};
    }
};