class Solution {
public:
    int upperBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
    
        while (left < right) {
            int mid = left + (right - left) / 2;
        
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    
        return left;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        

        vector<int> ans;
        for (auto query : queries) {
            int index = upperBound(nums, query);
            ans.push_back(index);
        }
        
        return ans;
    }
};