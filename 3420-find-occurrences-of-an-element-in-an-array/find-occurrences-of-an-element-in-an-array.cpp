class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ans;
        vector<int> temp;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == x)
                temp.push_back(i);
        }
        
        for(auto q: queries){
            if(q-1 < temp.size())
                ans.push_back(temp[q-1]);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};