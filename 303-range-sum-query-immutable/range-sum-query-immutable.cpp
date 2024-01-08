class NumArray {
public:
    vector<int> nums;
    vector<int> dp;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        dp.resize(n);
        prefixSum(nums);
    }

    void prefixSum(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++) {
            (i == 0) ? dp[i] = nums[i] : dp[i] = nums[i] + dp[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return left - 1 >= 0 ? dp[right] - dp[left-1] : dp[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */