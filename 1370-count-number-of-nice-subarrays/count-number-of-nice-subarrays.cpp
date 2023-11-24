class Solution {
public:
    int subArrays(vector<int>& nums, int k){
        int l = 0, h = 0, cnt = 0, ans = 0;

        while(h<nums.size()){
            if(nums[h] % 2 != 0){
                cnt++;
            }
            while(cnt > k){
                if(nums[l] & 2 != 0){
                    cnt--;
                }
                l++;
            }
            ans += h - l + 1;
            h++;
        }


        return ans;
    } 
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subArrays(nums, k) - subArrays(nums, k - 1);
    }
};