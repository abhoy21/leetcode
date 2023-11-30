class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void calc(vector<int>& candidates, int target, int i)
    {
        if(i == candidates.size())
        {
            if(target == 0)
                ans.push_back(v);
            return;
        }
        
        if(candidates[i] <= target)
            {
                v.push_back(candidates[i]);
                calc(candidates, target - candidates[i], i);
                v.pop_back();
            }
        calc(candidates, target, i+1);;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        calc(candidates, target, 0);
         return ans;

    }
};