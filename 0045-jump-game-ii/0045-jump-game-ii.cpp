class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int j = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            nums[i] = max(nums[i] + i, nums[i-1]); 
        }
        while(j < nums.size()-1)
        {
            j = nums[j];
            jump++;
        }
  

        return jump;
    }
};