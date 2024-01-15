class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int element = nums[i];
            while(element >= 1 && element <= nums.size() && nums[element - 1] != element){
                swap(nums[element - 1], element);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }

        return nums.size()+1;
    }
};
