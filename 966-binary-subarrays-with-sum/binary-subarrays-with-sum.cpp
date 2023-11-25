class Solution {
public:
    int func(vector<int>& nums, int goal){
        int l = 0, h, cnt = 0, ans = 0;
        if(goal < 0)
            return 0;
        for(h = 0; h < nums.size(); h++){
            cnt += nums[h];
            while(cnt > goal){
                cnt -= nums[l];
                l++;
            }
            ans += h - l + 1;
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums, goal) - func(nums, goal - 1);
    }
};