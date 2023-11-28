class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void func(vector<int>& nums, int ind){
        if(ind == nums.size()){
            ans.push_back(v);
            return;
        }

        v.push_back(nums[ind]);
        func(nums, ind+1);
        v.pop_back();
        func(nums, ind + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        func(nums, 0);

        return ans;
    }
};