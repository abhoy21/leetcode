class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> large;

        for(int i = 0;i<n-2;i++){

            int s = i+1;
            int l = n-1;
            
            while(s<l)
            {
                int sum = nums[i]+nums[s]+nums[l];
                if(sum==0){
                    large.insert({nums[i],nums[s],nums[l]});

                    s++;
                    l--;
                }
                else if(sum<0)
                {
                    s++;
                }else
                {
                    l--;
                }
            }

           
        }

       for(auto i : large){
           ans.push_back(i);
       }
       return ans;

    }
};