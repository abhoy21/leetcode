class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(vector<int> i : intervals)
        {
            if(ans.empty())
                ans.push_back(i);
            
            vector<int>& ptr = ans.back();

            if(i[0] <= ptr[1])
                ptr[1] = max(ptr[1], i[1]);
            else
                ans.push_back(i);
        }

        return ans;
    }
};