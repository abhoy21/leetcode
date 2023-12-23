class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                bool ok = true;
                int lst = -1;
                for(int k = 0; k < n; k++){
                    if(k >= i && k <= j)
                        continue;
                    else{
                        ok &= lst < nums[k];
                        lst = nums[k];
                    }
                }
                ans += ok;
            }
        }

        return ans;
    }
};