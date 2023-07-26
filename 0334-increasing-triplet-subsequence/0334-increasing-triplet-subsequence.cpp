class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if( nums.size() < 3)
            return false;
        else
        {
            int right = INT_MAX;
            int left = INT_MAX;
            for(int i = 0; i< nums.size(); i++)
            {
                if(nums[i]> right)
                    return true;
                else if(nums[i]>left && nums[i]<right)
                    right = nums[i];
                else if(nums[i] < left)
                    left = nums[i];
            }
        }
        
        return false;
    }
};