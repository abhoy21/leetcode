class Solution {
public:
    int func(vector<int>& nums, int mid){
        int sum = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] > mid){
                sum = nums[i];
                cnt++;
            }
            else sum += nums[i];
        }

        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxele = INT_MIN, sum = 0;

        for(int n : nums){
            if(n > maxele)
                maxele = n;
            sum += n;
        }

        int low = maxele, high = sum, ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int temp = func(nums, mid);
            if(temp >= k){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};