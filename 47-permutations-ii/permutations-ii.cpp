class Solution {
public:
    void permuteU(set<vector<int>>& ans, vector<int>& nums, int ind)
    {
        if(ind == nums.size())
        {
            ans.insert(nums);
            return;
        }

        for(int i = ind; i < nums.size(); i++)
        {
            swap(nums[i], nums[ind]);
            permuteU(ans, nums, ind+1);
            swap(nums[i], nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        permuteU(ans, nums, 0);
        vector<vector<int>> result;
        for(auto it: ans)
            result.push_back(it);
        return result;
    }
};