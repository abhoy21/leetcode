class Solution {
public:
    
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int l = 0;
        int r = nums.size() - 1;
        int k = nums.size() - 1; 
        
        while(l<=r)
        {
            if(abs(nums[l]) >= abs(nums[r]))
            {
                res[k--] = nums[l] * nums[l]; 
                l++;
            }
            else if(abs(nums[r]) >= abs(nums[l]))
            {
                res[k--] = nums[r] * nums[r];
                r--;
            }
        }
        
        return res;
    }
};



