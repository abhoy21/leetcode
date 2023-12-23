class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<long long> prefix;
        long long sum = 0;
        for(auto n : nums){
            prefix.push_back(sum);
            sum += n;
        }
        for(int i = nums.size()-1; i >= 2; i--){
            if(prefix[i] > nums[i])
                return prefix[i] + (long long)nums[i];
        }
        return -1;
    }
};