class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int rs = 0;
        int as = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            rs += i+1;
            as += nums[i];
        }

        return rs - as;
    
    }
};