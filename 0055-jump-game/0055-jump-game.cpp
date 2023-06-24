class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int dest = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > dest)
                return false;
            else
                dest = max(dest, i + nums[i]);
        }
        return true;
    }
};