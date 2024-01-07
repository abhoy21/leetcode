class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1] + 1)
                break;
            ans += nums[i];
        }

        set<int> st;
        for(int &i : nums)
            st.insert(i);
        for(int i = 0; i < nums.size(); i++) {
            if(!(st.count(ans) == 0))
                ans++;
        }

        return ans;
    }
};