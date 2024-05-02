class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l= 0, r = nums.size() - 1, ans = 0;
        while(l < r){
            int temp = nums[l] + nums[r];
            if(temp == 0){
                ans = max(ans, nums[r]);
                l++;
                r--;
            }
            else if(temp < 0)
                l++;
            else
                r--;
        }

        return ans == 0 ? -1 : ans;
    }
};