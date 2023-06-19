class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=1;
        int ele=nums[0];

        for(int i=1;i<nums.size();i++){
            if(freq == 0) ele=nums[i];

            ele==nums[i]?freq++:freq--;
        }
        return ele;
    }
};