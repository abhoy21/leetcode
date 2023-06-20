class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxi = INT_MIN;
        int i = 0, j = nums.size()-1;
        sort(nums.begin(), nums.end());
        while(i<j){
            maxi = max(maxi, (nums[i]+nums[j]));
            i++;
            j--;
        }
        
        return maxi;
    }
};