class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int prevMin = -1; 
        int prevMax = -1;
        for(int s = -1, r = 0; r < nums.size(); r++){
            if(nums[r] < minK || nums[r] > maxK)
                s = r;
            if(nums[r] == minK)
                prevMin = r;
            if(nums[r] == maxK)
                prevMax = r;
            
            ans += max(0, min(prevMin, prevMax) - s);
        }

        return ans;
    }
};