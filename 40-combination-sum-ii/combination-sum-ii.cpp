class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        func(candidates, target, 0, current, result);
        return result;
    }

private:
    void func(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;  // Skip duplicates
            }
            
            if (candidates[i] > target) {
                break;  // Stop if the candidate is greater than the remaining target
            }
            
            current.push_back(candidates[i]);
            func(candidates, target - candidates[i], i + 1, current, result);
            current.pop_back();
        }
    }
};