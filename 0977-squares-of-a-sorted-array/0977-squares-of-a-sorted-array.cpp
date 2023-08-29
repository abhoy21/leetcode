class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int l = 0;
        int r = nums.size() - 1;
        int k = nums.size() - 1;

        while(l<=r)
        {
            if(abs(nums[l]) >= abs(nums[r]))
            {
                ans[k--] = nums[l] * nums[l];
                l++;
            }
            else if(abs(nums[l]) <= abs(nums[r]))
            {
                ans[k--] = nums[r] * nums[r];
                r--;
            }
        }

        return ans;
    }
};