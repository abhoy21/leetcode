class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool leftbias)
    {
        int low = 0, high = nums.size() - 1;
        int pos = -1;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(target > nums[mid])
                low = mid + 1;
            else if(target < nums[mid])
                high = mid - 1;
            else{
                pos = mid;
                if(leftbias == true)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return pos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);

        return {left, right};
    }
};