class Solution {
public:
    void subset(int idx, vector<int>& nums, vector<int>& x, vector<vector<int>>& ans)
    {
        if(idx == nums.size())
        {
            ans.push_back(x);
            return;
        }
        x.push_back(nums[idx]);
        subset(idx+1, nums, x, ans);
        x.pop_back();
        subset(idx+1, nums, x, ans);     
    }

    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> x;
        subset(0,nums,x,ans);
        
        return ans;
        
    }
};