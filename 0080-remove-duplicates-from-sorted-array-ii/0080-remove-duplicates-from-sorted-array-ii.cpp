class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() < 3) {
            return nums.size();
        }


        int next_pos = 2; 


        for (size_t i = 2; i < nums.size(); ++i) {

            if (nums[i] != nums[next_pos - 2]) {

                nums[next_pos] = nums[i];
                ++next_pos;
            }
        }

        return next_pos;
    }
};