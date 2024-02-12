class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ele;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0)
                ele = nums[i];
            ele == nums[i] ? cnt++ : cnt--;
        }

        return ele;
    }
};