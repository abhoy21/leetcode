class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int freq = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(freq==0)
                ele = nums[i];
            (ele==nums[i])? freq++:freq--;
        }
        
        return ele;
    }
};