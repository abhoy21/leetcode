class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void makesubsets(vector<int>& nums, int i)
    {
        if(i == nums.size())
        {
            ans.push_back(v);
            return;
        }
        
        v.push_back(nums[i]);
        makesubsets(nums, i+1);
        v.pop_back();
        makesubsets(nums, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        makesubsets(nums,0);

        return ans;
    }
};