class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int S = 0;
        int ls = 0;
        for(int x: nums)
            S += x;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(ls == S - ls - nums[i])
                return i;
            
            ls += nums[i];
        }
        
        return -1;
    }
};