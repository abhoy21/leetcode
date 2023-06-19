class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int low =0;
        int high =nums.size()-1;

        int mid = low+(high-low);

        while(low<=high){
           if(nums[mid]==target){
               return mid;
           }
           else if(target>nums[mid]){
               low = mid+1;
           }
           else{
               high = mid-1;
           } 
           mid = low+(high-low);
        }

        return high+1;
    }
};