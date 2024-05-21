class Solution {
public:
    void func(vector<int>& nums, vector<vector<int>>& ans, vector<int>& v, int i){
        if(i == nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[i]);
        func(nums,ans,v, i+1);
        v.pop_back();
        func(nums, ans, v, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;

        func(nums, ans, v, 0);
        return ans;
    }
};