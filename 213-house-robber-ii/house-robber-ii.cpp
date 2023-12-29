class Solution {
public:
    int func(vector<int> &a){
        int prev = 0, prev2 = 0;

        for(int i = 0; i < a.size(); i++){
            int take = a[i];
            if(i > 1)
                 take += prev2;
            int nottake = 0 + prev;
            int cur = max(take, nottake);

            prev2 = prev;
            prev = cur;
        }

        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int> temp1, temp2;
        for(int i = 0; i < nums.size(); i++){
            if(i != 0)
                temp1.push_back(nums[i]);
            if(i != nums.size() - 1)
                temp2.push_back(nums[i]);
        }

        return max(func(temp1), func(temp2));
    }
};