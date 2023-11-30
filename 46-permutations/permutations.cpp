class Solution {
public:

    vector<vector<int>> ans;
    void func(vector<int>& nums, int ind){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = ind; i < nums.size(); i++){
            swap(nums[ind], nums[i]);
            func(nums, ind+1);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        func(nums, 0);

        return ans;
    }
};