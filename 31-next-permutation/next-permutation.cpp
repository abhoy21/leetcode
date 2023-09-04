class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int infp = -1; 
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                infp = i - 1;
                break;
            }
        }

        if (infp == -1) {
            reverse(nums.begin(), nums.end());
        }
         else {

            int smallestLargerIdx = infp + 1;
            for (int i = infp + 2; i < n; i++) {
                if (nums[i] > nums[infp] && nums[i] <= nums[smallestLargerIdx]) {
                    smallestLargerIdx = i;
                }
            }
            swap(nums[infp], nums[smallestLargerIdx]);
            reverse(nums.begin() + infp + 1, nums.end());
        }
    }
};
