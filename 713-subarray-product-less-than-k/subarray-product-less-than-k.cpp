class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        int l = 0, p = 1, cnt = 0;
        for(int r = 0; r < nums.size(); r++){
            p *= nums[r];

            while(p >= k && l < nums.size()){
                p /= nums[l];
                l++;
            }
            cnt += p < k ? r - l + 1 : 0;
        }

        return cnt;
    }
};