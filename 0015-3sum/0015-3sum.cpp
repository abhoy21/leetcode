class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int b, c;
        vector<vector<int>> ans;
        set<vector<int>>v;
        for(int i = 0; i<nums.size(); i++)
        {
            b = i+1;
            c = nums.size() - 1;
            while(b<c)
            {
                int sum = nums[i] + nums[b] + nums[c];
                if(sum == 0)
                {
                    v.insert({nums[i],nums[b],nums[c]});
                    b++;
                    c--;
                }
                else if( sum < 0)
                    b++;
                else
                    c--;
            }
        }

        for(auto i: v)
            ans.push_back(i);

        return ans;
    }
};