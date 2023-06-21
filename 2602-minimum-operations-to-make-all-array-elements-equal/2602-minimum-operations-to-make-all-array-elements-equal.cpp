class Solution {
public:
    int lowerBound(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right){
             int mid = left + (right - left) / 2;
            
            if(nums[mid] < target)
                    left = mid +1;
                
            else
                right = mid;
        }
        
        if(nums[left] != target && nums[left]< target)
            left = right +1;
        
        return left;
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<long long> prefix(nums.size() + 1), suffix(nums.size() + 1);
        for (int i = 1; i <= nums.size(); i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        for (int i = nums.size() - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + nums[i];
        

        vector<long long> ans;
        for (auto query : queries) {
            long long index = lowerBound(nums, query);
            long long val = (index * query) - prefix[index] + suffix[index] - ((nums.size() - index) * query);
                
            ans.push_back(val);
        }

        return ans;
    }
};